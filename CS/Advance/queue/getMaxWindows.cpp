#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *next, *prev;
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Deque {
   public:
    Node *head, *tail;
    Deque() {
        this->head = NULL;
        this->tail = NULL;
    }

    int *peekFront() {
        if (this->head == NULL) return NULL;
        return &this->head->data;
    }

    int *peekBack() {
        if (this->tail == NULL) return NULL;
        return &this->tail->data;
    }

    void enqueueFront(int data) {
        if (this->head == NULL) {
            this->head = new Node(data);
            this->tail = this->head;
        } else {
            Node *node = new Node(data);
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
    }

    void enqueueBack(int data) {
        if (this->head == NULL) {
            this->head = new Node(data);
            this->tail = this->head;
        } else {
            Node *node = new Node(data);
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
    }

    int *dequeueFront() {
        if (this->head == NULL) return NULL;

        Node *temp = this->head;
        this->head = this->head->next;
        if (this->head != NULL)
            this->head->prev = NULL;
        else
            this->tail = NULL;
        return &temp->data;
    }

    int *dequeueBack() {
        if (this->tail == NULL) return NULL;

        Node *temp = this->tail;
        this->tail = this->tail->prev;

        if (this->tail != NULL)
            this->tail->next = NULL;
        else
            this->head = NULL;
        return &temp->data;
    }
};

vector<int> getMaxWindows(vector<int> numList, int segment) {
    vector<int> result;
    if (numList.size() < segment) {
        int maxNum = INT_MIN;
        for (int num : numList) {
            maxNum = max(maxNum, num);
        }
        result.push_back(maxNum);
        return result;
    } else {
        Deque deque;
        // 最初の組みを計算する
        for (int i = 0; i < segment; i++) {
            while (deque.peekBack() != NULL &&
                   numList[*deque.peekBack()] <= numList[i]) {
                deque.dequeueBack();
            }
            deque.enqueueBack(i);
        }

        for (int i = segment; i < numList.size(); i++) {
            // 先頭は最大値
            result.push_back(numList[*deque.peekFront()]);

            // i-segmentは、検索対象の先頭文字
            while (deque.peekFront() != NULL &&
                   *deque.peekFront() <= i - segment) {
                deque.dequeueFront();
            }

            // 新しく入ってくる値よりも小さい場合は二度と使用されることはない
            while (deque.peekBack() != NULL &&
                   numList[*deque.peekBack()] <= numList[i]) {
                deque.dequeueBack();
            }
            deque.enqueueBack(i);
        }
        result.push_back(numList[*deque.peekFront()]);
    }

    return result;
}

void printArray(vector<int> intArr) {
    cout << "[";
    for (int i = 0; i < intArr.size(); ++i) {
        cout << intArr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    printArray(
        getMaxWindows({34, 35, 64, 34, 10, 2, 14, 5, 353, 23, 35, 63, 23}, 4));
}