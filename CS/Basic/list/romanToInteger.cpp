#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

int romanToInteger(string romanNumber)
{
    // ちょっとローマ数字のルールと違うとこ路もあるが
    // 今回はスタックと、連想配列の練習のためだけなので、考慮しない
    int convertedNumber = 0;

    map<char, int> ROMAN_NUMBER = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    stack<int> stackRomanNumber;
    for (int i = 0; i < romanNumber.length(); i++)
    {
        int number = ROMAN_NUMBER[romanNumber[i]];
        if (stackRomanNumber.empty())
        {
            stackRomanNumber.push(number);
        }
        else
        {
            if (stackRomanNumber.top() < number)
            {
                convertedNumber -= stackRomanNumber.top();
            }
            else
            {
                convertedNumber += stackRomanNumber.top();
            }
            stackRomanNumber.pop();
            stackRomanNumber.push(number);
        }
    }
    if (!stackRomanNumber.empty())
        convertedNumber += stackRomanNumber.top();

    return convertedNumber;
}

int main()
{
    cout << romanToInteger("MCMXCIII") << endl;
    return 0;
}