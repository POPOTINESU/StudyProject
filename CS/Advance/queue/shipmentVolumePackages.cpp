#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
   public:
    Node* head;
    Node* tail;

    Queue() : head(nullptr), tail(nullptr) {}

    optional<int> peekFront() {
        if (this->head == nullptr) return nullopt;
        return this->head->data;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    optional<int> dequeue() {
        if (this->head == nullptr) return nullopt;
        Node* headNode = this->head;
        int data = headNode->data;
        this->head = this->head->next;
        if (this->head == nullptr) {
            this->tail = nullptr;
        }
        delete headNode;
        return data;
    }

    bool isEmpty() const { return this->head == nullptr; }
};

optional<int> choiceMinimumPair(Queue* queue, Queue* packageQueue) {
    if (queue->isEmpty() && packageQueue->isEmpty()) {
        return nullopt;
    } else if (queue->isEmpty() ||
               (!packageQueue->isEmpty() &&
                packageQueue->peekFront() < queue->peekFront())) {
        return packageQueue->dequeue();
    } else {
        return queue->dequeue();
    }
}

int shipmentVolumePackages(vector<int> packages) {
    if (packages.size() == 1) return 0;
    sort(packages.begin(), packages.end());

    Queue queue;
    Queue packageQueue;
    int sumPackage = 0;

    for (int i : packages) {
        queue.enqueue(i);
    }

    while (!(queue.head == nullptr && packageQueue.head == nullptr)) {
        int firstItem = choiceMinimumPair(&queue, &packageQueue).value_or(0);
        int secondItem = choiceMinimumPair(&queue, &packageQueue).value_or(0);

        int package = firstItem + secondItem;
        sumPackage += package;

        if (!queue.isEmpty() || !packageQueue.isEmpty()) {
            packageQueue.enqueue(package);
        }
    }

    return sumPackage;
}