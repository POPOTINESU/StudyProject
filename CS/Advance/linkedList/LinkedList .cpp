#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    };
};

class LinkedList
{
public:
    SinglyLinkedListNode *head;

    LinkedList(SinglyLinkedListNode *head)
    {
        this->head = head;
    }
};

SinglyLinkedListNode *getLinkedList(vector<int> arr)
{
    SinglyLinkedListNode *node = new SinglyLinkedListNode(arr[0]);
    LinkedList *linkedList = new LinkedList(node);

    SinglyLinkedListNode *currentNode = linkedList->head;

    for (int i = 1; i < arr.size(); i++)
    {
        currentNode->next = new SinglyLinkedListNode(arr[i]);

        currentNode = currentNode->next;
    }

    return linkedList->head;
}