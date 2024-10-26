#include <iostream>
#include <vector>
using namespace std;

int findPeakHelper(vector<int> &arr, int start, int end)
{
    if (start == end)
        return arr[start];

    int center = (start + end) / 2;

    if ((center == 0 || arr[center] >= arr[center - 1]) &&
        (center == arr.size() - 1 || arr[center] >= arr[center + 1]))
        return arr[center];

    if (center > 0 && arr[center] < arr[center - 1])
    {
        return findPeakHelper(arr, start, center - 1);
    }

    // これまでに存在しない場合は、右半分にある
    return findPeakHelper(arr, center + 1, end);
}

int findPeak(vector<int> arr)
{
    if (arr.size() == 1)
        return arr[0];

    return findPeakHelper(arr, 0, arr.size() - 1);
}