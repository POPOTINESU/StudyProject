#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    };
};

class SinglyLinkedList {
   public:
    SinglyLinkedListNode* head;

    SinglyLinkedList(SinglyLinkedListNode* head) { this->head = head; }

    void addNodeFirst(SinglyLinkedListNode* newNode) {
        newNode->next = this->head;
        this->head = newNode;
    }
};

SinglyLinkedListNode* insertAtHead(SinglyLinkedListNode* head, int data) {
    SinglyLinkedList* linkedList = new SinglyLinkedList(head);

    linkedList->addNodeFirst(new SinglyLinkedListNode(data));

    return linkedList->head;
}
