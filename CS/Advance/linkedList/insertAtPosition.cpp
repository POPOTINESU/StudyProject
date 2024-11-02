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

SinglyLinkedListNode* insertAtPosition(SinglyLinkedListNode* head, int position, int data){
    int index = 0;
    SinglyLinkedListNode* currentNode = head;

    while (currentNode != NULL)
    {
        if (index == position){
            SinglyLinkedListNode* prevNext = currentNode->next;
            currentNode->next = new SinglyLinkedListNode(data);
            currentNode->next->next = prevNext;
        }
        currentNode = currentNode->next;
        index ++;
    }
    
    return head;
}