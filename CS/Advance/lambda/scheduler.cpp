#include <functional>
#include <iostream>
#include <string>

using namespace std;

class Item {
   public:
    function<void()> data;
    Item* next = nullptr;

    Item(function<void()> data) { this->data = data; }
};

class Queue {
   public:
    Item* head = nullptr;
    Item* tail = nullptr;

    function<void()> peekFront() const {
        return (this->head != nullptr) ? this->head->data : nullptr;
    }

    void enqueue(function<void()> task) {
        Item* newItem = new Item(task);
        if (this->head == nullptr && this->tail == nullptr) {
            this->head = newItem;
            this->tail = newItem;
        } else {
            this->tail->next = newItem;
            this->tail = newItem;
        }
    }

    function<void()> dequeue() {
        function<void()> task = peekFront();
        if (task != nullptr) {
            Item* nextTask = this->head->next;
            delete this->head;
            this->head = nextTask;
            if (this->head == nullptr) {
                this->tail = nullptr;
            }
        }
        return task;
    }
};

class TaskQueue {
   public:
    Queue* queue = new Queue();

    void push(function<void()> task) { queue->enqueue(task); }
    bool taskExists() { return queue->peekFront() ? true : false; }
    void run() {
        function<void()> task = queue->dequeue();
        if (task) task();
    }
};

function<void()> firstTask = []() {
    cout << "Running the first function!!!" << endl;
};
function<void()> secondTask = []() {
    cout << "Running the second function~~~" << endl;
};
function<void()> thirdTask = []() {
    cout << "Running the third function>>>" << endl;
};
function<void()> fourthTask = []() {
    cout << "Running the fourth function<<<" << endl;
};

void entry() {
    TaskQueue* scheduler = new TaskQueue();
    scheduler->push(firstTask);
    scheduler->push(secondTask);
    scheduler->push(thirdTask);
    scheduler->push(fourthTask);

    while (scheduler->taskExists()) scheduler->run();

    delete scheduler;
}