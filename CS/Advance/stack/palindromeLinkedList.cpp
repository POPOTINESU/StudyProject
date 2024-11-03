#include <cmath>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Item {
   public:
    int data;
    Item* next;

    Item(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
   public:
    Item* head;

    Stack() { this->head = nullptr; }

    void push(int data) {
        Item* temp = this->head;
        this->head = new Item(data);
        this->head->next = temp;
    }

    optional<int> pop() {
        if (this->head == nullptr) return std::nullopt;
        Item* temp = this->head;
        this->head = this->head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    optional<int> peek() {
        if (this->head == nullptr) return std::nullopt;
        return this->head->data;
    }
};

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    };
};

bool palindromeLinkedList(SinglyLinkedListNode* head) {
    Stack stack;

    SinglyLinkedListNode* currenNode = head;

    while (currenNode != nullptr) {
        stack.push(currenNode->data);
        currenNode = currenNode->next;
    }

    currenNode = head;
    while (currenNode != nullptr) {
        if (currenNode->data != stack.pop()) return false;

        currenNode = currenNode->next;
    }

    return true;
}
