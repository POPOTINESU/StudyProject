#include <iostream>
#include <optional>
#include <string>

using namespace std;

class Item {
   public:
    int data;
    Item* prev;
    Item* next;

    Item(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class Deque {
   public:
    Item* head;
    Item* tail;

    Deque() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    optional<int> peekFront() {
        if (this->head == nullptr) return nullopt;
        return this->head->data;
    }
    optional<int> peekBack() {
        if (this->head == nullptr) return nullopt;
        return this->tail->data;
    }

    void enqueueFront(int data) {
        Item* newItem = new Item(data);
        if (this->head == nullptr) {
            this->head = newItem;
            this->tail = newItem;

            this->head->next = this->tail;
            this->tail->prev = this->head;
        } else {
            Item* prevHead = this->head;
            this->head = newItem;
            newItem->next = prevHead;
            prevHead->prev = newItem;
        }
    }

    void enqueueBack(int data) {
        Item* newItem = new Item(data);
        if (this->head == nullptr) {
            this->head = newItem;
            this->tail = newItem;
        } else {
            this->tail->next = newItem;
            newItem->prev = this->tail;
            this->tail = newItem;
        }
    }

    optional<int> dequeueFront() {
        if (this->head == nullptr) return nullopt;

        int answer = this->head->data;
        Item* headNext = this->head->next;
        delete this->head;
        this->head = headNext;

        return answer;
    }

    optional<int> dequeueBack() {
        if (this->tail == nullptr) return nullopt;

        int answer = this->tail->data;
        Item* prevTail = this->tail->prev;
        delete this->tail;
        this->tail = prevTail;

        return answer;
    }
};

void entry() {
    Deque* q = new Deque();

    q->enqueueBack(4);
    q->enqueueBack(50);
    cout << q->peekFront().value() << endl;
    cout << q->peekBack().value() << endl;

    q->enqueueFront(36);
    q->enqueueFront(96);

    cout << q->peekFront().value() << endl;
    cout << q->peekBack().value() << endl;

    cout << q->dequeueBack().value() << endl;
    cout << q->dequeueBack().value() << endl;

    cout << q->peekFront().value() << endl;
    cout << q->peekBack().value() << endl;

    q->enqueueFront(20);
    cout << q->dequeueBack().value() << endl;
}