#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
using namespace std;

int shuffleSuccessRate(vector<int> arr, vector<int> shuffledArr)
{
    int movedIndexCount = 0;
    // 順番が入れ替わっただけで、個数は減っていない
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != shuffledArr[i])
            movedIndexCount++;
    }

    return int(floor(double(movedIndexCount) / double(arr.size()) * 100.0));
}
