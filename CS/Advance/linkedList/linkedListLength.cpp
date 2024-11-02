#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

class SinglyLinkedListNode{
    public:
        int data;
        SinglyLinkedListNode *next;
        SinglyLinkedListNode(int data){
            this->data = data;
            this->next = NULL;
        };
};

int linkedListLength(SinglyLinkedListNode* head){
    int count = 0;
    SinglyLinkedListNode *currentNode = head;
    while (currentNode != NULL)
    {
        count ++;
        currentNode = currentNode->next;
    }
    return count;
}