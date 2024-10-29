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

SinglyLinkedListNode* removeNthNode(SinglyLinkedListNode* head, int n) {
    if (n == 0) return head;

    SinglyLinkedListNode dummy = SinglyLinkedListNode(0);
    dummy.next = head;
    SinglyLinkedListNode* first = &dummy;
    SinglyLinkedListNode* second = &dummy;

    // n+1回のループを回す
    for (int count = 0; count <= n; count++) {
        if (first == NULL) return dummy.next;
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // secondは、n-1なので、n番目をスキップする
    second->next = second->next->next;

    return dummy.next;
}
