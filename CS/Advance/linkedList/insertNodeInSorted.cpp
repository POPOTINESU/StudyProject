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

    SinglyLinkedListNode* changeHeadNode(SinglyLinkedListNode* newHead) {
        newHead->next = this;
        return newHead;
    }
};

SinglyLinkedListNode* insertNodeInSorted(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (data <= head->data) return head->changeHeadNode(newNode);

    SinglyLinkedListNode* currentNode = head;
    SinglyLinkedListNode* prevNode = NULL;

    while (currentNode->next != NULL && currentNode->data < data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (prevNode->data <= data && data <= currentNode->data) {
        prevNode->next = newNode;
        newNode->next = currentNode;
    } else {
        currentNode->next = newNode;
    }
    return head;
}