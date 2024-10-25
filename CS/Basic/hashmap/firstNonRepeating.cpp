#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int firstNonRepeating(string s)
{
    map<char, int> solveQuestionCount;

    for (char c : s)
    {
        if (solveQuestionCount.find(c) != solveQuestionCount.end())
            solveQuestionCount[c]++;
        else
            solveQuestionCount[c] = 1;
    }

    for (int i = 0; i < s.length(); i++)
    {   
        
        if (solveQuestionCount[s[i]] == 1)
            return i;
    }

    return -1;
}
