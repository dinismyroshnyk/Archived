import socket, threading, pickle

class Client:
    def __init__(self, host='127.0.0.1', port=5555):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((host, port))
        self.connected = True
        self.chars = []

    def send_data(self, data):
        if self.connected:
            message = pickle.dumps(data)
            self.client.send(message)

    def receive(self):
        while self.connected:
            try:
                data = self.client.recv(1024)
                if data:  # Check if the data is not empty
                    message = pickle.loads(data)
                    #print(f"Received data: {message}")
                    if message == 'server disconnect':
                        print('The server has closed.')
                        self.disconnect()
                        return
                    elif message == 'server full':
                        print('This server is currently full.')
                        self.disconnect()
                        return
                    elif isinstance(message, tuple) and message[0] == 'characters':
                        self.handle_character_assignments(message[1])
            except Exception as e:
                print('An error occured or the game window was closed.')
                print('Error:', e)
                self.disconnect()
                break

    def handle_character_assignments(self, characters):
        self.chars = characters

    def disconnect(self):
        if self.connected:
            self.connected = False
            try:
                print('Disconnecting from server...')
                self.send_data('disconnect')
            except ConnectionResetError:
                pass
            self.client.close()

    def run(self):
        receive_thread = threading.Thread(target=self.receive)
        receive_thread.start()