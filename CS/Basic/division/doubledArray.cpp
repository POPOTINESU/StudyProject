#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> doubledArrayHelper(vector<int> arr, int start, int end)
{
    if (start == end)
    {
        vector<int> nodeAnswer = {arr[start] * 2};
        return nodeAnswer;
    }

    int middle = (start + end) / 2;
    vector<int> left = doubledArrayHelper(arr, start, middle);
    vector<int> right = doubledArrayHelper(arr, middle + 1, end);

    for (int num : right)
    {
        left.push_back(num);
    }

    return left;
}

vector<int> doubledArray(vector<int> arr)
{
    // 分割統治法
    return doubledArrayHelper(arr, 0, arr.size() - 1);
}