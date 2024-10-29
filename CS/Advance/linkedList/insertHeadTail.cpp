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

SinglyLinkedListNode* insertHeadTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* currentNode = new SinglyLinkedListNode(data);

    // 先頭に挿入
    currentNode->next = head;
    SinglyLinkedListNode* firstNode = currentNode;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    // 末尾に挿入
    currentNode->next = new SinglyLinkedListNode(data);

    return firstNode;
}
