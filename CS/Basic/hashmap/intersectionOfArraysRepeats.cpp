#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> intersectionOfArraysRepeats(vector<int> intList1, vector<int> intList2)
{
    // value : count
    // countの回数だけ配列に追加する
    vector<int> duplicateList;
    vector<int> longList = (intList1 >= intList2) ? intList1 : intList2;
    vector<int> minList = (intList1 < intList2) ? intList1 : intList2;
    map<int, int> countNum;

    for (int i = 0; i < longList.size(); i++)
    {
        if (countNum.find(longList[i]) != countNum.end())
            countNum[longList[i]] ++;
        else
            countNum[longList[i]] = 1;
    }

    for (int i = 0; i < minList.size(); i++)
    {
        if (countNum.find(minList[i]) != countNum.end() && countNum[minList[i]] != 0)
        {
            duplicateList.push_back(minList[i]);
            cout << minList[i] << endl;
            countNum[minList[i]]--;
        }
    }
    sort(duplicateList.begin(), duplicateList.end());
    return duplicateList;
}
