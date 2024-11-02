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

vector<int> consecutiveWalk(vector<int> arr) {
    vector<int> answer;
    Stack *stack = new Stack();
    for (int n : arr) {
        if (stack->peek() < n) {
            stack->push(n);
        } else {
            while (stack->pop() != NULL);
            stack->push(n);
        }
    }
    
    while (stack->head != NULL)
    {
        answer.push_back(stack->pop());
    }
    return answer;
}