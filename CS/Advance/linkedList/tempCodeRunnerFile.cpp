#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node {
   public:
    int data;
    Node *prev, *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
   public:
    Node *head, *tail;

    DoublyLinkedList(vector<int> arr) {
        if (arr.size() <= 0) return;

        this->head = new Node(arr[0]);
        Node *currentNode = this->head;

        for (int i = 1; i < arr.size(); i++) {
            currentNode->next = new Node(arr[i]);
            currentNode->next->prev = currentNode;
            currentNode = currentNode->next;
        }

        this->tail = currentNode;
    }
};

void entry() {
    DoublyLinkedList *numList =
        new DoublyLinkedList(vector{1, 2, 3, 4, 5, 6, 7});

    cout << numList->head->data << endl;
    cout << numList->head->next->data << endl;
    cout << numList->head->next->prev->data << endl;
    cout << numList->tail->data << endl;
    cout << numList->tail->prev->data << endl;
    cout << numList->tail->prev->prev->data << endl;
}