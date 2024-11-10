#include <iostream>
#include <vector>

using namespace std;

class Heap {
   public:
    static int left(int index) { return 2 * index + 1; }
    static int right(int index) { return 2 * index + 2; }
    static int parent(int index) { return (index + 1) / 2; }

    static void maxHeapify(vector<int> &heap, int lastIndex, int index) {
        int largest = index;
        int leftChild = Heap::left(index);
        int rightChild = Heap::right(index);

        if (leftChild < lastIndex && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < lastIndex && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(heap, lastIndex, largest);
        }
    }

    static void buildMaxHeap(vector<int> &heap) {
        int middle = Heap::parent(heap.size());
        for (int i = middle; i >= 0; i--)
            Heap::maxHeapify(heap, heap.size(), i);
    }

    static void heapSort(vector<int> &heap) {
        buildMaxHeap(heap);

        int lastIndex = heap.size()-1;
        while (lastIndex > 0)
        {
            int temp = heap[lastIndex];
            heap[lastIndex] = heap[0];
            heap[0] = temp;

            lastIndex --;
            maxHeapify(heap, lastIndex, 0);
        }
        
    }
};

int main() {
    vector<int> heap = {2, 42, 11, 30, 10, 7, 6, 5, 9};
    Heap::heapSort(heap);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}