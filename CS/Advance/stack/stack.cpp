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
void entry() {
    Stack *s1 = new Stack();

    s1->push(2);
    cout << s1->peek() << endl;

    s1->push(4);
    s1->push(3);
    s1->push(1);

    cout << s1->pop() << endl;

    cout << s1->peek() << endl;

    Stack *s2 = new Stack();
    s2->pop();
    s2->push(9);
    s2->push(8);
    cout << s2->peek() << endl;
}
