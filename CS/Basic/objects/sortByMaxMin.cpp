#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> sortByMaxMin(vector<int> arr)
{
    vector<int> sortedArray;
    sort(arr.rbegin(), arr.rend());

    int sortedLength = arr.size() / 2;

    for (int i = 0; i < sortedLength; i++)
    {
        sortedArray.push_back(arr[i]);
        sortedArray.push_back(arr[arr.size()-i -1]);
    }

    if (arr.size() % 2 != 0)
        sortedArray.push_back(arr[sortedLength]);

    return sortedArray;
}