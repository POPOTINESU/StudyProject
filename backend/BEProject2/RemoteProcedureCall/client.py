import json
import socket
from typing import Any


class RPCClient:
    def __init__(self, server_address: str) -> None:
        self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.server_address = server_address
        self.connect()

    def connect(self) -> None:
        print(f"Connecting to {self.server_address}")
        self.socket.connect(self.server_address)

    def send_message(self, message: dict) -> None:
        json_message = json.dumps(message).encode("utf-8")
        print(f"Sending message {message}")
        self.socket.sendall(json_message)

    def receive_response(self) -> dict:
        response = self.socket.recv(1024)
        message = response.decode("utf-8")
        print(f"Received response: {message}")
        return json.loads(message)

    def call_remote_method(self, class_name: str, method: str, args: list) -> Any:
        message = {"class": class_name, "method": method, "args": args}
        self.send_message(message)
        response = self.receive_response()
        return response.get("result", None)

    def close(self) -> None:
        print("Closing connection")
        self.socket.close()


if __name__ == "__main__":
    client = RPCClient("/tmp/socket_file")

    result = client.call_remote_method("Math", "floor", [5.7])
    print(f"Result of Math.floor: {result}")

    result = client.call_remote_method("String", "reverse", ["hello"])
    print(f"Result of String.reverse: {result}")

    client.close()
