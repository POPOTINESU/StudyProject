#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <climits>

using namespace std;

vector<int> mergeSort(vector<int> arr)
{
    if (arr.size() > 1)
    {
        int middle = arr.size() / 2;

        vector<int> leftArr(arr.begin(), arr.begin() + middle);
        vector<int> rightArr(arr.begin() + middle, arr.begin() + arr.size());

        leftArr = mergeSort(leftArr);
        rightArr = mergeSort(rightArr);

        int leftIndex = 0;
        int rightIndex = 0;
        int insertIndex = 0;

        leftArr.push_back(INT_MAX);
        rightArr.push_back(INT_MAX);

        while (leftIndex + rightIndex < arr.size())
        {
            if (leftArr[leftIndex] <= rightArr[rightIndex])
            {
                arr[insertIndex] = leftArr[leftIndex];
                leftIndex++;
            }
            else
            {
                arr[insertIndex] = rightArr[rightIndex];
                rightIndex++;
            }
            insertIndex++;
        }
    }

    return arr;
}
