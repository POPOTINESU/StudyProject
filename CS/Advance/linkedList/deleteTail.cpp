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

SinglyLinkedListNode* deleteTail(SinglyLinkedListNode* head) {
    if (head->next == NULL) return NULL;

    SinglyLinkedListNode* currentNode = head;
    SinglyLinkedListNode* prevNode = NULL;

    while (currentNode->next != NULL) {
        SinglyLinkedListNode* tempNode = currentNode;
        currentNode = currentNode->next;
        prevNode = tempNode;
    }

    prevNode->next = NULL;

    return head;
}