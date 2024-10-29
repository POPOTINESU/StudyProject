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

SinglyLinkedListNode* middleNode(SinglyLinkedListNode* head) {
    vector<SinglyLinkedListNode*> listNodeArray;

    while (head != NULL) {
        listNodeArray.push_back(head);
        head = head->next;
    }

    return listNodeArray[listNodeArray.size() / 2];
}
