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

    int getNodeLength() {
        SinglyLinkedListNode* currentNode = this;
        int length = 0;
        while (currentNode != NULL) {
            length++;
            currentNode = currentNode->next;
        }
        return length;
    }

    SinglyLinkedListNode* getAtNode(int position) {
        SinglyLinkedListNode* currentNode = this;
        for (int i = 0; i < position; i++) {
            if (currentNode == NULL) return NULL;
            currentNode = currentNode->next;
        }

        return currentNode;
    }
};

int findMergeNode(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    int headALength = headA->getNodeLength();
    int headBLength = headB->getNodeLength();

    headA = (headALength > headBLength)
                ? headA->getAtNode(headALength - headBLength)
                : headA;
    headB = (headBLength > headALength)
                ? headB->getAtNode(headBLength - headALength)
                : headB;

    int answer = -1;
    while (headA != NULL) {
        if (headA->data != headB->data)
            answer = -1;
        else if (answer == -1)
            answer = headA->data;

        headA = headA->next;
        headB = headB->next;
    }

    return answer;
}
