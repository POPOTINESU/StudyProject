#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int totalChar(string s)
{
    int totalCharNums = 0;
    for (int i = 0; i < s.length(); i++)
    {
        totalCharNums += tolower(s[i]);
    }

    return totalCharNums;
}

bool isFirstStringLarger(string s1, string s2)
{
    return totalChar(s1)> totalChar(s2);
}
