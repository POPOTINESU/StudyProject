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

    void addNode(SinglyLinkedListNode* newNode) {
        SinglyLinkedListNode* tempNode = this->next;
        this->next = newNode;
        newNode->next = tempNode;
    }
};

class SinglyLinkedList {
   public:
    SinglyLinkedListNode* head;

    SinglyLinkedList(SinglyLinkedListNode* head) { this->head = head; }
};

SinglyLinkedListNode* doubleEvenNumber(SinglyLinkedListNode* head) {
    SinglyLinkedList* linkedList = new SinglyLinkedList(head);

    SinglyLinkedListNode* currentNode = linkedList->head;

    int index = 0;
    while (currentNode != NULL) {
        if (index % 2 == 0) {
            currentNode->addNode(
                new SinglyLinkedListNode(currentNode->data * 2));
            currentNode = currentNode->next->next;
        } else
            currentNode = currentNode->next;
        index++;
    }

    return linkedList->head;
}
