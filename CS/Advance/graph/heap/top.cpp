#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PriorityQueue {
   public:
    vector<int> heap;
    PriorityQueue(vector<int> heap) {
        make_heap(heap.begin(), heap.end());
        for (int n : heap) this->heap.push_back(n);
    }

    int top() { return this->heap[0]; }
};

void entry() {
    PriorityQueue pq1 = PriorityQueue(vector<int>{2, 3, 43, 2, 53, 6, 75, 10});
    cout << pq1.top() << endl;

    PriorityQueue pq2 = PriorityQueue(vector<int>{3, 12, 0, 2, 9, 1, 65, 32});
    cout << pq2.top() << endl;

    PriorityQueue pq3 =
        PriorityQueue(vector<int>{1, 2, 3, 4, 8, 2, 1, 9, 7, 3, 4});
    cout << pq3.top() << endl;
}