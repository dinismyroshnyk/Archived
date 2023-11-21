import socket

class Client:
    def __init__(self, server):
        self.server = server
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((self.server.host, self.server.port))

    def connect(self):
        pass

    def disconnect(self):
        pass

    def send(self, data):
        pass

# Not sure if anything here works at all