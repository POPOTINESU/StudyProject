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

void minHeapify(vector<int>& arr, int arrayEnd, int index) {
    int minimumIndex = index;
    int left = leftIndex(index);
    int right = rightIndex(index);

    if (left < arrayEnd && arr[left] < arr[minimumIndex]) minimumIndex = left;
    if (right < arrayEnd && arr[right] < arr[minimumIndex])
        minimumIndex = right;

    if (minimumIndex != index) {
        swap(arr[index], arr[minimumIndex]);
        minHeapify(arr, arrayEnd, minimumIndex);
    }
}

vector<int> buildMinHeap(vector<int> intArr) {
    int parent = parentIndex(intArr.size() - 1);
    for (int i = parent; i >= 0; i--) minHeapify(intArr, intArr.size(), i);

    return intArr;
}

int main() {
    for (int i : buildMinHeap(vector<int>{3, 2, 1})) cout << i << " ";
    cout << endl;
    return 0;
}
