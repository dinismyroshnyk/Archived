import socket, threading

class Server:
    def __init__(self):
        self.host = socket.gethostname()
        self.port = 5555
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((self.host, self.port))
        self.server.listen()

    def start(self):
        print(f"Server started on {self.host}:{self.port}")
        while True:
            client, address = self.server.accept()
            print(f"Connected to {address}")
            thread = threading.Thread(target=self.handle_client, args=(client,))
            thread.start()

    def handle_client(self, client):
        while True:
            data = client.recv(1024).decode('utf-8')
            if not data: break
            print(f"Received: {data}")
            client.send(data.encode('utf-8'))
        client.close()

# Not sure if anything here works at all