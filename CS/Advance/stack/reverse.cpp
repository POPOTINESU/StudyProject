#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Item {
   public:
    int data;
    Item *next;

    Item(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
   public:
    Item *head;

    Stack() { this->head = NULL; }

    void push(int data) {
        Item *temp = this->head;
        this->head = new Item(data);
        this->head->next = temp;
    }

    int pop() {
        if (this->head == NULL) return NULL;
        Item *temp = this->head;
        this->head = this->head->next;
        return temp->data;
    }

    int peek() {
        if (this->head == NULL) return NULL;
        return this->head->data;
    }
};

vector<int> reverse(vector<int> arr) {
    // 逆からforすれば済むがあえてstackで実装
    Stack *stack = new Stack();
    vector<int> reverseArray;
    for (int n : arr) {
        stack->push(n);
    }

    for (int i = 0; i < arr.size(); i++) {
        reverseArray.push_back(stack->pop());
    }

    return reverseArray;
}
