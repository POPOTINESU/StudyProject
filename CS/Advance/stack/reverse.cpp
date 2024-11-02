#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// ここもスタックは自分で作る

class Item {
   public:
    int data;
    Item *next;

    Item(int data) { this->data = data; }

    Item *getLastItem() {
        Item *currentItem = this;

        while (currentItem->next != NULL) {
            currentItem = currentItem->next;
        }
        return currentItem;
    }

    int removeLastItem() {
        Item *currentItem = this;
        Item *prevItem = NULL;

        if (currentItem == NULL) return NULL;

        while (currentItem->next != NULL) {
            prevItem = currentItem;
            currentItem = currentItem->next;
        }

        if (prevItem) prevItem->next = NULL;

        return currentItem->data;
    }
};

class Stack {
   public:
    Item *head;

    Stack() { this->head = NULL; }

    void push(int data) {
        if (this->head == NULL)
            this->head = new Item(data);
        else {
            Item *lastItem = this->head->getLastItem();
            lastItem->next = new Item(data);
        }
    }

    int pop() { return this->head->removeLastItem(); }

    int peek() { return this->head->getLastItem()->data; }
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
