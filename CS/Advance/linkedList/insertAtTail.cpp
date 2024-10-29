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

    void addLastNode(SinglyLinkedListNode* newLastNode) {
        if (this->next == NULL) {
            this->next = newLastNode;
        }
    }
};

SinglyLinkedListNode* insertAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* currentNode = head;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->addLastNode(new SinglyLinkedListNode(data));

    return head;
}
