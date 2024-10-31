import socket
import os

sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

server_address = '/tmp/socket_file'

try:
    os.unlink(server_address)
except FileNotFoundError:
    pass

print(f"Starting up on {server_address}")

sock.bind(server_address)

sock.listen(1)

while True:
    print("Waiting for a connection")
    connection, client_address = sock.accept()
    try:
        print("Connection from", client_address)
        
        while True:
            READ_BYTE = 64  # Increased buffer size for testing
            data = connection.recv(READ_BYTE)
            if data:
                data_str = data.decode("utf-8")
                print(f"Received data: {data_str}")
                
                response = "Processing " + data_str
                connection.sendall(response.encode())
            else:
                print("No data from", client_address)
                break
    finally:
        print("Closing current connection")
        connection.close()