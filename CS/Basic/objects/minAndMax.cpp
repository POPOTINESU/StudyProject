#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> minAndMax(vector<int> intArr)
{
    vector<int> minAndMaxList = {0, 0};

    int MIN_NUM = 100000;
    int MAX_NUM = 0;

    int TOTAL_PRICE = 0;
    for (int i = 0; i < intArr.size(); i++)
    {
        MIN_NUM = min(MIN_NUM, intArr[i]);
        MAX_NUM = max(MAX_NUM, intArr[i]);

        TOTAL_PRICE += intArr[i];
    }

    minAndMaxList[0] = TOTAL_PRICE - MAX_NUM;
    minAndMaxList[1] = TOTAL_PRICE - MIN_NUM;

    return minAndMaxList;
}