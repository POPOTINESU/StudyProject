from typing import Any


class Queue:
    def __init__(self, values: list = [], capacity=1_000_000) -> None:
        self.values = values
        self.capacity = capacity

    def enqueue(self, value) -> None:
        if len(self.values) <= self.capacity:
            self.values.append(value)
        else:
            raise ValueError("capacity over")

    def dequeue(self) -> Any:
        if len(self.values) == 0:
            raise ValueError
        pop_value = self.values[0]
        self.values = self.values[1:]

        return pop_value

    def isEmpty(self) -> bool:
        return len(self.values) == 0

    def isFull(self) -> bool:
        return len(self.values) == self.capacity


def round_robin():
    process_total, time_slice = map(int, input().split(" "))
    
    if time_slice <= 0:
        raise ValueError("time slice is least 1")

    processes = Queue()
    for _ in range(process_total):
        pid, time = input().split(" ")
        processes.enqueue([pid, int(time)])

    while not processes.isEmpty():
        process = processes.dequeue()
        process[1] -= time_slice
        if process[1] <= 0:
            print(f"finish PID: {process[0]}")
        else:
            print(f"PID: {process[0]} Remaining time {process[1]}")
            processes.enqueue(process)

    print("finish all tasks")


if __name__ == "__main__":
    round_robin()