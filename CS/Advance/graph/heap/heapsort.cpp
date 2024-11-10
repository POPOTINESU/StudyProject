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

void maxHeapify(vector<int>& arr, int arrayEnd, int index) {
    int longest = index;
    int left = leftIndex(index);
    int right = rightIndex(index);

    if (left < arrayEnd && arr[left] > arr[longest]) longest = left;
    if (right < arrayEnd && arr[right] > arr[longest]) longest = right;

    if (longest != index) {
        swap(arr[longest], arr[index]);
        maxHeapify(arr, arrayEnd, longest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int parent = parentIndex(arr.size() - 1);
    for (int i = parent; i >= 0; i--) maxHeapify(arr, arr.size(), i);
}

vector<int> heapsort(vector<int> intArr) {
    buildMaxHeap(intArr);
    int lastIndex = intArr.size() - 1;
    while (lastIndex >= 0) {
        swap(intArr[0], intArr[lastIndex]);
        lastIndex--;
        maxHeapify(intArr, lastIndex + 1, 0);
    }

    return intArr;
}

int main() {
    for (int i : heapsort(vector<int>{3, 2, 1})) cout << i << " ";
    cout << endl;
    return 0;
}