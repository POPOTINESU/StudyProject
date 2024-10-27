#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList(vector<int> arr)
    {
        this->head = arr.size() > 0 ? new Node(arr[0]) : NULL;
        Node *currentNode = this->head;
        for (int i = 1; i < arr.size(); i++)
        {
            currentNode->next = new Node(arr[i]);
            currentNode = currentNode->next;
        }
    }

    Node *at(int index)
    {
        Node *iterator = this->head;
        for (int i = 0; i < index; i++)
        {
            iterator = iterator->next;
            if (iterator == NULL)
                return NULL;
        }
        return iterator;
    }

    // ここからfindNode関数を作成してください。
    Node *findNode(int targetValue)
    {
        Node *currentNode = this->head;
        while (currentNode != NULL)
        {
            if (currentNode->data == targetValue)
                return currentNode;
            currentNode = currentNode->next;
        }

        Node *notFindNode = NULL;
        return notFindNode;
    }
};

int main()
{

    SinglyLinkedList *numList = new SinglyLinkedList({35, 23, 546, 67, 86, 234, 56, 767, 34, 1, 98, 78, 555});

    cout << numList->findNode(23)->data << endl;
}