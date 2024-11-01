import json
import math
import os
import socket
from typing import Any


class TCPConnection:
    def __init__(self, server_address: str) -> None:
        self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.server_address = server_address

    def bind(self) -> None:
        try:
            os.unlink(self.server_address)
        except FileNotFoundError:
            print("file not found")

        self.socket.bind(self.server_address)


class Math:
    def floor(self, x: float) -> int:
        return int(math.floor(x))

    def nroot(self, n: int, x: int) -> float:
        return math.pow(x, 1 / n)


class String:
    def reverse(self, s: str) -> str:
        return s[::-1]

    def validateAnagram(self, str1: str, str2: str) -> bool:
        if len(str1) != len(str2):
            return False

        str1_dict = self._addCount(str1)
        str2_dict = self._addCount(str2)

        for char in str1_dict:
            if str1_dict[char] != str2_dict.get(char, 0):
                return False

        return True

    def sort(self, str_array: list[str]) -> list[str]:
        str_array.sort()
        return str_array

    def _addCount(self, string: str) -> dict:
        str_dict = {}
        for s in string:
            if s in str_dict:
                str_dict[s] += 1
            else:
                str_dict[s] = 1
        return str_dict


class RPC:
    def __init__(self, connection: TCPConnection) -> None:
        self.socket = connection.socket
        self.server_address = connection.server_address

    def sendMessage(self, message: dict) -> None:
        json_message = json.dumps(message).encode("utf-8")
        print(f"send message {message}")
        self.socket.sendall(json_message)

    def callFunction(self) -> Any:
        message, _ = self._readMessage()

        classParam = message.get("class", None)
        methodParam = message.get("method", None)
        args = message.get("args", [])

        classInstance = self._classInstance(classParam)

        result = self._callFunction(classInstance, methodParam, args)
        self.sendMessage({"result": result})

    def _classInstance(self, classParam: str) -> Any:
        if classParam == "Math":
            return Math()
        elif classParam == "String":
            return String()
        else:
            raise ValueError(f"class not found: {classParam}")

    def _callFunction(self, classInstance: Any, methodName: str, args: list) -> Any:
        method = getattr(classInstance, methodName, None)
        if not method:
            raise ValueError(
                f"method {methodName} not found in {classInstance.__class__.__name__}"
            )
        return method(*args)

    def _readMessage(self) -> tuple[dict, str]:
        json_message, address = self.socket.recvfrom(1024)
        message = json_message.decode("utf-8")
        print(f"receive message {message} from {address}")

        message_dict = json.loads(message)
        return message_dict, address
