import socket
import os
sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)

server_address = "/tmp/udp_socket_file"

address = "/tmp/udp_client_socket_file"

message = b"Message to send to the client."

try:
    os.unlink(address)
except FileNotFoundError:
    pass

sock.bind(address)

try:
    print(f"sending{message}")
    sent = sock.sendto(message, server_address)
    
    print("waiting to receive")
    
    data, server = sock.recvfrom(4096)
    
    print(f"received {data}")
    
finally:
    print("closing socket")
    sock.close()

