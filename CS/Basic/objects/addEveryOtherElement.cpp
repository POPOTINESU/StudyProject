#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int addEveryOtherElement(vector<int> intArr)
{
    int oddTotalNums = 0;

    for (int i = 0; i < intArr.size(); i += 2)
    {
        oddTotalNums += intArr[i];
    }

    return oddTotalNums;
}
