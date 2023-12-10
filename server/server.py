import socket, threading, pickle

class Server:
    def __init__(self, game_size_logic, host = '127.0.0.1', port = 5555, max_clients = 4):
        self.game_size_logic = game_size_logic
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((host, port))
        self.server.listen()
        self.clients = []
        self.max_clients = max_clients
        self.client_identifiers = {} # For debugging purposes
        self.lock = threading.Lock()
        self.chars = [{'assigned_to': None, 'controlled': False, 'position': (0, 0)} for _ in range(4)]
        self.running = True
        for i, char in enumerate(self.chars):
            char['position'] = (self.game_size_logic[0] / 2, self.game_size_logic[1] / 2 + i * 60)  # Assign a default position to each character
        print(f'Server started on {host}:{port}')

    def send_chars_data(self):
        for connected_client in self.clients.copy():  # Use copy to avoid modifying the list while iterating
            chars_without_sockets = [{'controlled': char['controlled'], 'position': char['position'], 'assigned_to': self.client_identifiers.get(connected_client) if char['assigned_to'] == connected_client else None} for char in self.chars]
            try:
                data = pickle.dumps(('characters', chars_without_sockets))
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
        for char in self.chars: 
            client = char['assigned_to']
            if client is not None:
                client_id = self.client_identifiers.get(client, 'Unknown client')
                print(f'assigned_to: {client_id}, controlled: {char["controlled"]}')
            else:
                print(char)
        print('-' * 20)

    def assign_client_id(self, client): # Debug method
        if client not in self.client_identifiers:
            self.client_identifiers[client] = f'Client {len(self.client_identifiers) + 1}'

    def switch_character(self, client, direction):
        with self.lock:
            client_chars = [char for char in self.chars if char['assigned_to'] == client]
            curr_char = next((char for char in client_chars if char['controlled']), None)
            if curr_char is None:
                return
            curr_index = client_chars.index(curr_char)
            new_index = (curr_index + direction) % len(client_chars)
            new_char = client_chars[new_index]
            curr_char['controlled'] = False
            new_char['controlled'] = True
            self.send_chars_data()
            self.debug()  # Debug line

    def assign_characters(self):
        with self.lock:
            num_clients = len(self.clients)
            prev_assignments = self.chars.copy()
            self.chars = [{'assigned_to': None, 'controlled': False, 'position': char['position']} for char in self.chars]
            if num_clients == 1:
                for i, char in enumerate(self.chars):
                    if prev_assignments[i]['controlled'] and prev_assignments[i]['assigned_to'] in self.clients:
                        char['assigned_to'] = prev_assignments[i]['assigned_to']
                        char['controlled'] = True
                    else: char['assigned_to'] = self.clients[0]
                if not any(char['controlled'] for char in self.chars):
                    self.chars[0]['controlled'] = True
            elif num_clients == 2:
                for i, char in enumerate(self.chars):
                    if prev_assignments[i]['controlled'] and prev_assignments[i]['assigned_to'] in self.clients:
                        char['assigned_to'] = prev_assignments[i]['assigned_to']
                        char['controlled'] = True
                        next_controlled_index = (i + 2) % 4
                        next_index = (i + 1) % 4
                        if prev_assignments[next_index]['assigned_to'] is None:
                            self.chars[next_index]['assigned_to'] = prev_assignments[i]['assigned_to']
                        elif prev_assignments[next_index]['assigned_to'] in self.clients:
                            self.chars[next_index]['assigned_to'] = prev_assignments[next_index]['assigned_to']
                prev_unique_clients = len(set(char['assigned_to'] for char in prev_assignments if char['assigned_to'] is not None))
                for i, char in enumerate(self.chars):
                    if char['assigned_to'] is None:
                        if prev_unique_clients == 1:
                            char['assigned_to'] = self.clients[1]
                        else:
                            if prev_assignments[i]['assigned_to'] in self.clients:
                                char['assigned_to'] = prev_assignments[i]['assigned_to']
                            else: char['assigned_to'] = self.clients[1]
                if (prev_assignments[next_controlled_index]['assigned_to'] in self.clients and
                    not self.chars[next_controlled_index]['assigned_to'] == self.clients[0]):
                    self.chars[next_controlled_index]['controlled'] = True
            elif num_clients == 3:
                for i, char in enumerate(self.chars):
                    if prev_assignments[i]['controlled'] and prev_assignments[i]['assigned_to'] in self.clients:
                        char['assigned_to'] = prev_assignments[i]['assigned_to']
                        char['controlled'] = True
                    elif prev_assignments[i]['assigned_to'] == self.clients[0] or prev_assignments[i]['assigned_to'] not in self.clients:
                        char['assigned_to'] = self.clients[0]
                    else:
                        char['assigned_to'] = self.clients[2]
                        char['controlled'] = True
            elif num_clients == 4:
                for i, char in enumerate(self.chars):
                    if prev_assignments[i]['controlled'] and prev_assignments[i]['assigned_to'] in self.clients:
                        char['assigned_to'] = prev_assignments[i]['assigned_to']
                        char['controlled'] = True
                    else:
                        char['assigned_to'] = self.clients[3]
                        char['controlled'] = True
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
                        for i in range(len(self.chars)):
                            if self.chars[i]['assigned_to'] == client:
                                self.chars[i]['position'] = message[i]['position']
                        self.send_chars_data()
            except:
                try:
                    if client.fileno() != -1:
                        print(f'Client {client.getpeername()} has disconnected.')
                except OSError:
                    print('The client is already disconnected.')
                if client in self.clients:
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
                if len(self.clients) < self.max_clients:
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