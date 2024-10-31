import os
import socket

sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
server_address = "/tmp/server"
client_address = "/tmp/client"

try:
    os.unlink(client_address)
except FileNotFoundError:
    pass

sock.bind(client_address)

try:
    message = input().encode()
    
    print(f"sending message: {message}")
    sent = sock.sendto(message, server_address)
    
    print("waiting to receive")
    
    data, server = sock.recvfrom(4096)
    
    received_data = data.decode()
    print(f"received {received_data}")

finally:
    print("closing socket")
    sock.close()



