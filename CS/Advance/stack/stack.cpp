#include <iostream>
#include <string>

using namespace std;

// stackの自作
// あえてのlinkedList

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
