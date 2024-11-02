#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    };
};

int linkedListLastValue(SinglyLinkedListNode *head) {
    SinglyLinkedListNode *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}