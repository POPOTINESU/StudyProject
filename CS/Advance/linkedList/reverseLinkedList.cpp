#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
using namespace std;

class SinglyLinkedListNode {
   public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

SinglyLinkedListNode* reverseLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* prevNode = NULL;
    SinglyLinkedListNode* current = head;

    while (current != NULL) {
        SinglyLinkedListNode* tempNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = tempNode;
    }

    return prevNode;  // 反転後の新しい先頭ノードを返す
}