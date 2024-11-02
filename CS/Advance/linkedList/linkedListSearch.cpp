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

int linkedListSearch(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* currentNode = head;

    int index = 0;
    while (currentNode != NULL) {
        if (currentNode->data == data) return index;
        currentNode = currentNode->next;
        index++;
    }

    return -1;
}
