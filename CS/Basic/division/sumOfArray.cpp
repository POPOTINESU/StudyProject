#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int sumOfArrayHelper(vector<int> arr, int start, int end)
{
    if (start == end)
        return arr[start];

    int middle = (start + end) / 2;
    int left = sumOfArrayHelper(arr, start, middle);
    int right = sumOfArrayHelper(arr, middle + 1, end);

    return left + right;
}

int sumOfArray(vector<int> arr)
{
    return sumOfArrayHelper(arr, 0, arr.size() - 1);
}