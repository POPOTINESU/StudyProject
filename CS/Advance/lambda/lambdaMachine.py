import math
from typing import Any


class LambdaMachine:
    def __init__(self) -> None:
        self.handlers = {}
        self.counter = 0
        self.lambdaStorage = []

    def insert(self, key, callable) -> None:
        self.handlers[key] = callable
        self.lambdaStorage.append(key)

    def retrieve(self, key) -> Any:
        return self.handlers.get(key)

    def roundRobinRetrieve(self) -> Any:
        func = self.handlers[self.lambdaStorage[self.counter]]
        self.counter = self.counter + 1 if self.counter < len(self.lambdaStorage)-1 else 0
        return func


# powだとint型でオーバーヘッドがあるため
# 推奨されないがlambdaの練習
pythagora = lambda x, y: int(math.sqrt((x * x) + (y * y)))
addition = lambda x, y: x + y
multiplication = lambda x, y: x * y

lambdaMachine = LambdaMachine()
lambdaMachine.insert("pythagora", pythagora)

lambdaMachine.insert("addition", addition)
lambdaMachine.insert("multiplication", multiplication)
print(lambdaMachine.roundRobinRetrieve()(6, 8))
print(lambdaMachine.roundRobinRetrieve()(6, 8))
print(lambdaMachine.roundRobinRetrieve()(6, 8))
print(lambdaMachine.roundRobinRetrieve()(6, 8))
