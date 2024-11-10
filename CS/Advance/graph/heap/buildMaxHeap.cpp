#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int leftIndex(int index) { return 2 * index + 1; }
int rightIndex(int index) { return 2 * index + 2; }
int parentIndex(int index) { return (index - 1) / 2; }

void maxHeapify(vector<int> &arr, int arrayEnd, int index) {
    int largest = index;
    int left = leftIndex(index);
    int right = rightIndex(index);

    if (left < arrayEnd && arr[left] > arr[largest]) largest = left;
    if (right < arrayEnd && arr[right] > arr[largest]) largest = right;

    if (largest != index) {
        swap(arr[largest], arr[index]);
        maxHeapify(arr, arrayEnd, largest);
    }
}

vector<int> buildMaxHeap(vector<int> intArr) {
    int parent = parentIndex(intArr.size() - 1);
    for (int i = parent; i >= 0; i--) maxHeapify(intArr, intArr.size(), i);

    return intArr;
}

int main() {
    for (int i : buildMaxHeap(vector<int>{1, 2, 3})) cout << i << " ";
    cout << endl;
    return 0;
}
