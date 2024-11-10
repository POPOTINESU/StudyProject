#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PriorityQueue {
   public:
    vector<int> heap;

    PriorityQueue(vector<int> arr) {
        buildMaxHeap(arr);
        this->heap = arr;
    }

    int top() {
        if (!this->heap.empty()) return this->heap[0];
        return -1;
    }

    int pop() {
        int answer = this->top();
        int lastIndex = this->heap.size() - 1;
        swap(this->heap[0], this->heap[lastIndex]);
        this->heap.pop_back();

        maxHeapify(this->heap, lastIndex, 0);

        return answer;
    }

   private:
    void maxHeapify(vector<int>& arr, int indexEnd, int rootIndex) {
        int largest = rootIndex;
        int leftIndex = leftChild(rootIndex);
        int rightIndex = rightChild(rootIndex);

        if (leftIndex < indexEnd && arr[leftIndex] > arr[largest])
            largest = leftIndex;
        if (rightIndex < indexEnd && arr[rightIndex] > arr[largest])
            largest = rightIndex;

        if (largest != rootIndex) {
            swap(arr[rootIndex], arr[largest]);
            maxHeapify(arr, indexEnd, largest);
        }
    }
    void buildMaxHeap(vector<int>& arr) {
        int parentIndex = parent(arr.size() - 1);
        for (int i = parentIndex; i >= 0; i--) {
            maxHeapify(arr, arr.size(), i);
        }
    }
    static int leftChild(int index) { return 2 * index + 1; }
    static int rightChild(int index) { return 2 * index + 2; }
    static int parent(int index) { return (index - 1) / 2; }
};

void entry() {
    PriorityQueue pq = PriorityQueue(vector<int>{2, 3, 43, 2, 53, 6, 75, 10});
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
    cout << pq.pop() << endl;
}

int main() {
    entry();
    return 0;
}