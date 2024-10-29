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

SinglyLinkedListNode* mergeTwoSortedLinkedLists(SinglyLinkedListNode* head1,
                                                SinglyLinkedListNode* head2) {
    // 値の先頭を表すだけなので、スタック上の制限で充分
    SinglyLinkedListNode dummy(0);
    SinglyLinkedListNode* current = &dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    while (head1 != NULL) {
        current->next = head1;
        head1 = head1->next;
        current = current->next;
    }

    while (head2 != NULL) {
        current->next = head2;
        head2 = head2->next;
        current = current->next;
    }

    return dummy.next;
}
