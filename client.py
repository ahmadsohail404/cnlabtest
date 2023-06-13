import socket

def client_program():
    host = socket.gethostbyname()
    port = 5001
    client_socket = socket.socket()
    client_socket.connect((host, port))

    message = input("->")

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())
        data = client_socket.recv(1024).decode()
        print("Received " + data)
        message = input("->")
    client_socket.close()

if __name__ == "__main__":
    client_program()