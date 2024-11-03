#include <iostream>
#include <optional>
#include <string>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) { this->data = data; }
};

class Queue {
   public:
    Node *head;
    Node *tail;

    Queue() {
        this->head = NULL;
        this->tail = NULL;
    }

    optional<int> peekFront() { return this->head->data; }

    optional<int> peekBack() { return this->tail->data; }

    void enqueue(int data) {
        Node *newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    optional<int> dequeue() {
        Node *headNode = this->head;
        if (this->head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        } else {
            this->head = this->head->next;
        }

        return headNode->data;
    }
};

void entry() {
    Queue q;

    q.enqueue(4);
    cout << q.peekFront().value() << endl;
    cout << q.peekBack().value() << endl;
    
    q.enqueue(50);
    cout << q.peekFront().value() << endl;
    cout << q.peekBack().value() << endl;

    q.enqueue(64);
    cout << q.peekFront().value() << endl;
    cout << q.peekBack().value() << endl;
    cout << q.dequeue().value() << endl;
}