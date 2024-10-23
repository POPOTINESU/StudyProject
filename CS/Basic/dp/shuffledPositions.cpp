#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

vector<int> shuffledPositions(vector<int> arr, vector<int> shuffledArr)
{
    map<int, int> sortedIndexMap;
    vector<int> moveToIndex;

    for (int i = 0; i < shuffledArr.size(); i++){
        sortedIndexMap[shuffledArr[i]] = i; 
    }

    for (int i = 0; i < arr.size(); i++){
        moveToIndex.push_back(sortedIndexMap[arr[i]]);
    }

    return moveToIndex;
}