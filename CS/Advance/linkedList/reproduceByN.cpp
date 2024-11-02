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

    int getLength() {
        SinglyLinkedListNode* currentNode = this;
        int length = 0;
        while (currentNode != NULL) {
            length++;
            currentNode = currentNode->next;
        }
        return length;
    }

    SinglyLinkedListNode* getTailNode() {
        SinglyLinkedListNode* currentNode = this;

        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        return currentNode;
    }
};

SinglyLinkedListNode* reproduceByN(SinglyLinkedListNode* head, int n) {
    int linkedListLength = head->getLength();
    SinglyLinkedListNode* currentNode = head;
    SinglyLinkedListNode* tailNode = head->getTailNode();

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < linkedListLength; j++) {
            tailNode->next = new SinglyLinkedListNode(currentNode->data);

            tailNode = tailNode->next;
            currentNode = currentNode->next;
        }
        currentNode = head;
    }

    return head;
}