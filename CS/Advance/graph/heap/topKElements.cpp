#include <cmath>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int left(int index) { return 2 * index + 1; }
int right(int index) { return 2 * index + 2; }
int parent(int index) { return (index - 1) / 2; }

void maxHeapify(vector<int>& arr, int arrayEnd, int index) {
    int longest = index;
    int leftIndex = left(index);
    int rightIndex = right(index);

    if (leftIndex < arrayEnd && arr[leftIndex] > arr[longest])
        longest = leftIndex;
    if (rightIndex < arrayEnd && arr[rightIndex] > arr[longest])
        longest = rightIndex;

    if (index != longest) {
        swap(arr[index], arr[longest]);
        maxHeapify(arr, arrayEnd, longest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int arrayEnd = arr.size();

    for (int i = parent(arrayEnd - 1); i >= 0; i--) {
        maxHeapify(arr, arrayEnd, i);
    }
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    int lastIndex = arr.size() - 1;

    while (lastIndex >= 0) {
        swap(arr[0], arr[lastIndex]);
        lastIndex--;
        maxHeapify(arr, lastIndex + 1, 0);
    }
}

vector<int> topKElements(vector<int> intArr, int k) {
    heapSort(intArr);
    vector<int> answer;
    for (int i = 0; i < k; i++) {
        answer.push_back(intArr.back());
        intArr.pop_back();
    }
    return answer;
}

int main() {}