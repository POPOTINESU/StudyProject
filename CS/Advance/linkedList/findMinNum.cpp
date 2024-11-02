#include <climits>
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

int findMinNum(SinglyLinkedListNode* head) {
    int minNumber = INT_MAX;
    int minIndex = 0;
    int currentIndex = 0;
    SinglyLinkedListNode* currentNode = head;

    while (currentNode != NULL) {
        // 最後の最小値のindexを返す
        if (minNumber >= currentNode->data) {
            minNumber = currentNode->data;
            minIndex = currentIndex;
        }
        currentIndex++;
        currentNode = currentNode->next;
    }

    return minIndex;
}
