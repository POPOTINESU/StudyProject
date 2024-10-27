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

int getIndexValue(SinglyLinkedListNode *head, int index)
{
    int currentIndex = 0;
    while (head != NULL)
    {
        cout << currentIndex << ":" << index << endl;
        // indexが通常と違って1つずれて指定されるため、index-1
        if (currentIndex== index-1)
            return head->data;
        head = head->next;
        currentIndex ++;
    }
    return 0;
}