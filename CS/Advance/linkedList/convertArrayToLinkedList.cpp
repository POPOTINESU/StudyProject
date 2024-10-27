#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList(Node *head)
    {
        this->head = head;
    }
};

SinglyLinkedList convertArrayToSinglyLinkedList(vector<int> &arr)
{
    Node *firstNode = new Node(arr[0]);
    SinglyLinkedList *singlyLinkedList = new SinglyLinkedList(firstNode);

    Node *currentNode = singlyLinkedList->head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        currentNode->next = newNode;

        currentNode = currentNode->next;
    }

    return *singlyLinkedList;
}

int main()
{
    vector<int> arr = {35, 23, 546, 67, 86, 234, 56, 767, 34, 1, 98, 78, 555};

    SinglyLinkedList answer = convertArrayToSinglyLinkedList(arr);

    Node *currentNode = answer.head;

    while (currentNode != NULL)
    {
        cout << (*currentNode).value << endl;

        currentNode = currentNode->next;
    }

    return 0;
}