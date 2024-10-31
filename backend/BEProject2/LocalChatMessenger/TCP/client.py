import socket
import sys

sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

server_address = '/tmp/socket_file'
print(f"Connecting to {server_address}")

try:
    sock.connect(server_address)
except socket.error as err:
    print(f"Socket error: {err}")
    ERROR_CODE = 1
    sys.exit(ERROR_CODE)

try:
    message = b"Sending a message to the server side"
    print("Sending data to server...")
    sock.sendall(message)  # Send message to server

    TIME_OUT_LIMIT = 20
    sock.settimeout(TIME_OUT_LIMIT)
    
    try:
        while True:
            data = sock.recv(32)
            if data:
                print(f"Server response: {data.decode('utf-8')}")
            else:
                break
    except TimeoutError:
        print("Socket timeout, ending listening for server messages")
finally:
    print("Closing socket")
    sock.close()