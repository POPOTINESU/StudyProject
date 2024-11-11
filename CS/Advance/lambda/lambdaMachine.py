from typing import Any
import math

class LambdaMachine:
    def __init__(self) -> None:
        self.handlers = {}

    def insert(self, key, callable) -> None:
        self.handlers[key] = callable

    def retrieve(self, key) -> Any:
        return self.handlers.get(key)


# powだとint型でオーバーヘッドがあるため
# 推奨されないがlambdaの練習
pythagora = lambda x, y: int(math.sqrt((x * x) + (y * y)))
addition = lambda x, y: x + y
multiplication = lambda x, y: x * y

lambdaMachine = LambdaMachine()
lambdaMachine.insert("pythagora", pythagora)
print(lambdaMachine.retrieve("pythagora")(3, 4))

lambdaMachine.insert("addition", addition)

print(lambdaMachine.retrieve("addition")(2, 5))

lambdaMachine.insert("multiplication", multiplication)

print(lambdaMachine.retrieve("multiplication")(4, 10))
