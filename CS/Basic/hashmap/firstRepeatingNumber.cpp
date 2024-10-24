#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int firstRepeatingNumber(vector<int> nums)
{
    int minIndexValue = nums.size() + 1;
    int firstDuplicateNum = -1;
    map<int, int> numToIndexMap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (numToIndexMap.find(nums[i]) != numToIndexMap.end())
        {
            if (minIndexValue > numToIndexMap[nums[i]])
            {
                minIndexValue = numToIndexMap[nums[i]];
                firstDuplicateNum = nums[i];
            }
        }
        numToIndexMap[nums[i]] = i;
    }
    return firstDuplicateNum;
}
