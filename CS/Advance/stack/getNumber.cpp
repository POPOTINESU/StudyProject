#include <iostream>
#include <optional>
#include <string>

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

    Stack() : head(nullptr) {}

    void push(int data) {
        Item* temp = new Item(data);
        temp->next = head;
        head = temp;
    }

    optional<int> pop() {
        if (head == nullptr) return std::nullopt;
        Item* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    optional<int> peek() const {
        if (head == nullptr) return std::nullopt;
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

string getNumber(const string& code) {
    if (code.length() > 8) return "0";

    Stack stack, tempStack;
    string answer = "";
    int lastUsedNumber = 1;
    tempStack.push(lastUsedNumber);

    for (char c : code) {
        if (c == 'I') {
            while (!stack.isEmpty()) {
                tempStack.push(stack.pop().value());
            }
            tempStack.push(++lastUsedNumber);
        } else if (c == 'D') {
            if (stack.isEmpty()) {
                stack.push(tempStack.pop().value());
            }
            stack.push(++lastUsedNumber);
        }
    }

    while (!tempStack.isEmpty()) {
        stack.push(tempStack.pop().value());
    }

    while (!stack.isEmpty()) {
        answer += to_string(stack.pop().value());
    }

    return answer;
}
