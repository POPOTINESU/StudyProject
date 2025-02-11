from typing import Optional


class ListNode:
    def __init__(self, key: int):
        self.key = key
        self.next: Optional["ListNode"] = None
        self.prev: Optional["ListNode"] = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, key: int):
        new_node = ListNode(key)
        if self.head is None:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def delete(self, key: int):
        current = self.head
        while current and current.key != key:
            current = current.next

        if current is None:
            return

        if current.prev:
            current.prev.next = current.next
        else:
            self.head = current.next

        if current.next:
            current.next.prev = current.prev
        else:
            self.tail = current.prev

    def delete_first(self):
        if self.head is None:
            return
        if self.head.next:
            self.head = self.head.next
            self.head.prev = None
        else:
            self.head = self.tail = None

    def delete_last(self):
        if self.tail is None:
            return
        if self.tail.prev:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            self.head = self.tail = None

    def print_list(self):
        current = self.head
        result = []
        while current:
            result.append(str(current.key))
            current = current.next
        print(" ".join(result))


if __name__ == "__main__":
    n = int(input())
    dll = DoublyLinkedList()

    for _ in range(n):
        command = input().split()
        if command[0] == "insert":
            dll.insert(int(command[1]))
        elif command[0] == "delete":
            dll.delete(int(command[1]))
        elif command[0] == "deleteFirst":
            dll.delete_first()
        elif command[0] == "deleteLast":
            dll.delete_last()

    dll.print_list()
