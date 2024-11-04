#include <cmath>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <vector>

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

int getMax(vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    Deque deque;
    deque.enqueueFront(arr[0]);

    for (int num : arr) {
        if (deque.peekFront() < num) deque.enqueueFront(num);
    }

    return deque.dequeueFront().value();
}