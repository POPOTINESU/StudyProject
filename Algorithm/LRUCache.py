from collections import OrderedDict


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.order_dict = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.order_dict:
            return -1
        self.order_dict.move_to_end(key)
        return self.order_dict[key]

    def put(self, key: int, value: int) -> None:
        if key in self.order_dict:
            self.order_dict.move_to_end(key)
        self.order_dict[key] = value
        if len(self.order_dict) > self.capacity:
            self.order_dict.popitem(last=False)
