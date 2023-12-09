import socket, threading, pickle

class Server:
    def __init__(self, host = '127.0.0.1', port = 5555):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((host, port))
        self.server.listen()
        self.clients = []
        self.client_identifiers = {} # For debugging purposes
        self.lock = threading.Lock()
        self.characters = [{'assigned_to': None, 'controlled': False, 'position': (0, 0)} for _ in range(4)]
        self.running = True
        for i, character in enumerate(self.characters):
            character['position'] = (0, i * 60)  # Assign a default position to each character
        print(f'Server started on {host}:{port}')

    def send_chars_data(self):
        for connected_client in self.clients.copy():  # Use copy to avoid modifying the list while iterating
            characters_without_sockets = [{'controlled': character['controlled'], 'position': character['position'], 'assigned_to': self.client_identifiers.get(connected_client) if character['assigned_to'] == connected_client else None} for character in self.characters]
            try:
                data = pickle.dumps(('characters', characters_without_sockets))
            except Exception as e:
                print(f'Error pickling data: {e}')
                continue
            try:
                connected_client.send(data)
            except:
                self.clients.remove(connected_client)  # Remove the client if an exception occurs

    def debug(self): # Debug method
        print('-' * 20)
        print('Characters: ')
        for character in self.characters: 
            client = character['assigned_to']
            if client is not None:
                client_id = self.client_identifiers.get(client, 'Unknown client')
                print(f'assigned_to: {client_id}, controlled: {character["controlled"]}')
            else:
                print(character)
        print('-' * 20)

    def assign_client_id(self, client): # Debug method
        if client not in self.client_identifiers:
            self.client_identifiers[client] = f'Client {len(self.client_identifiers) + 1}'

    def switch_character(self, client, direction):
        with self.lock:
            client_characters = [character for character in self.characters if character['assigned_to'] == client]
            current_character = next((character for character in client_characters if character['controlled']), None)
            if current_character is None:
                return
            current_index = client_characters.index(current_character)
            new_index = (current_index + direction) % len(client_characters)
            new_character = client_characters[new_index]
            current_character['controlled'] = False
            new_character['controlled'] = True
            self.send_chars_data()
            self.debug()  # Debug line

    def assign_characters(self):
        with self.lock:
            num_clients = len(self.clients)
            previous_assignments = self.characters.copy()
            self.characters = [{'assigned_to': None, 'controlled': False, 'position': character['position']} for character in self.characters]
            if num_clients == 1:
                for i, character in enumerate(self.characters):
                    if previous_assignments[i]['controlled'] and previous_assignments[i]['assigned_to'] in self.clients:
                        character['assigned_to'] = previous_assignments[i]['assigned_to']
                        character['controlled'] = True
                    else: character['assigned_to'] = self.clients[0]
                if not any(character['controlled'] for character in self.characters):
                    self.characters[0]['controlled'] = True
            elif num_clients == 2:
                for i, character in enumerate(self.characters):
                    if previous_assignments[i]['controlled'] and previous_assignments[i]['assigned_to'] in self.clients:
                        character['assigned_to'] = previous_assignments[i]['assigned_to']
                        character['controlled'] = True
                        next_controlled_index = (i + 2) % 4
                        next_index = (i + 1) % 4
                        if previous_assignments[next_index]['assigned_to'] is None:
                            self.characters[next_index]['assigned_to'] = previous_assignments[i]['assigned_to']
                        elif previous_assignments[next_index]['assigned_to'] in self.clients:
                            self.characters[next_index]['assigned_to'] = previous_assignments[next_index]['assigned_to']
                previous_unique_clients = len(set(character['assigned_to'] for character in previous_assignments if character['assigned_to'] is not None))
                for i, character in enumerate(self.characters):
                    if character['assigned_to'] is None:
                        if previous_unique_clients == 1:
                            character['assigned_to'] = self.clients[1]
                        else:
                            if previous_assignments[i]['assigned_to'] in self.clients:
                                character['assigned_to'] = previous_assignments[i]['assigned_to']
                            else: character['assigned_to'] = self.clients[1]
                if (previous_assignments[next_controlled_index]['assigned_to'] in self.clients and
                    not self.characters[next_controlled_index]['assigned_to'] == self.clients[0]):
                    self.characters[next_controlled_index]['controlled'] = True
            elif num_clients == 3:
                for i, character in enumerate(self.characters):
                    if previous_assignments[i]['controlled'] and previous_assignments[i]['assigned_to'] in self.clients:
                        character['assigned_to'] = previous_assignments[i]['assigned_to']
                        character['controlled'] = True
                    elif previous_assignments[i]['assigned_to'] == self.clients[0] or previous_assignments[i]['assigned_to'] not in self.clients:
                        character['assigned_to'] = self.clients[0]
                    else:
                        character['assigned_to'] = self.clients[2]
                        character['controlled'] = True
            elif num_clients == 4:
                for i, character in enumerate(self.characters):
                    if previous_assignments[i]['controlled'] and previous_assignments[i]['assigned_to'] in self.clients:
                        character['assigned_to'] = previous_assignments[i]['assigned_to']
                        character['controlled'] = True
                    else:
                        character['assigned_to'] = self.clients[3]
                        character['controlled'] = True
            self.send_chars_data()

    def handle(self, client):
        while self.running:
            try:
                data = client.recv(1024)
                try:
                    message = pickle.loads(data)
                except Exception as e:
                    print(f'Error unpickling data: {e}')
                    continue
                if message == 'disconnect':
                    raise ConnectionError()
                elif message == 'switch_up':
                    self.switch_character(client, -1)
                elif message == 'switch_down':
                    self.switch_character(client, 1)
                elif isinstance(message, list):  # Check if the received message is a list
                    with self.lock:
                        for i in range(len(self.characters)):
                            if self.characters[i]['assigned_to'] == client:
                                self.characters[i]['position'] = message[i]['position']
                        self.send_chars_data()
            except:
                try:
                    if client.fileno() != -1:
                        print(f'Client {client.getpeername()} has disconnected.')
                except OSError:
                    print('The client is already disconnected.')
                self.clients.remove(client)
                self.assign_characters()
                self.debug() # Debug line
                self.send_chars_data()
                client.close()
                break

    def receive(self):
        while self.running:
            try:
                client, address = self.server.accept()
                if len(self.clients) < 4:
                    print(f'Client {address} has connected.')
                    self.clients.append(client)
                    self.assign_client_id(client)  # Debug line
                    self.assign_characters()
                    self.debug()  # Debug line
                    thread = threading.Thread(target=self.handle, args=(client,))
                    thread.start()
                else:
                    print(f"Attempted connection from {address}. Maximum connections reached.")
                    client.send(pickle.dumps('server full'))
                    client.close()
            except OSError:
                break

    def stop(self):
        self.running = False
        print('Stopping server...')
        for client in self.clients.copy():
            client.send(pickle.dumps('server disconnect'))
            try:
                print(f'Client {client.getpeername()} has disconnected.')
            except OSError:
                print('The client is already disconnected.')
            client.close()
        self.server.close()
        print('Server stopped.')

def run_server(server):
    server.receive()

def main():
    server = Server()
    server_thread = threading.Thread(target=run_server, args=(server,))
    server_thread.start()

    while True:
        command = input()
        if command == 'close':
            server.stop()
            break

if __name__ == '__main__':
    main()