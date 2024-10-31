import os
import socket
from faker import Faker

sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)

server_address = "/tmp/server"

try:
    os.unlink(server_address)
except FileNotFoundError:
    pass

print(f"starting up on {server_address}")

sock.bind(server_address)

while True:
    print("waiting to message")
    
    data, address = sock.recvfrom(4096)
    
    print(f"received {len(data)} bytes from {address}")
    print(data)
    
    if data:
        fake = Faker('ja_JP')
        fake_name = fake.name().encode()
        
        print(fake_name)
        sent = sock.sendto(fake_name, address)
        
        print(f"sent {data} bytes back to {address}")