from functools import reduce
from typing import Any, Callable


def toString(arr: list[str]) -> str:
    return reduce(lambda string, s: string + s, arr, "")


def concat(s1: str, s2: str) -> str:
    return s1 + s2


def capitalizeDecorator(callable: Callable) -> Callable:
    def uppercaseArray(arr: list[str]) -> Any:
        convertedArray = list(map(lambda x: x.upper(), arr))
        return callable(convertedArray)

    return uppercaseArray


def lowercaseResultDecorator(callable: Callable) -> Callable:
    def lowercaseArray(arr: list[str]) -> Any:
        convertedArray = list(map(lambda x: x.lower(), arr))
        return callable(convertedArray)

    return lowercaseArray


def printInfoDecorator(callable: Callable) -> Callable:
    def connect(s1: str, s2: str) -> str:
        answer = callable(s1, s2)
        return f"{s1} + {s2} = {answer}"

    return connect


arr = ["h", "E", "L", "L", "O"]

f1 = capitalizeDecorator(toString)

f2 = lowercaseResultDecorator(toString)

f3 = printInfoDecorator(concat)

print(f1(arr))
print(f2(arr))
print(f3(f1(arr), f2(arr)))
