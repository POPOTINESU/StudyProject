#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

bool isPangram(string string)
{
    map<char, bool> memo;
    for (char c = 'a'; c <= 'z'; c++)
    {
        memo[c] = false;
    }

    for (int i = 0; i < string.length(); i++)
    {
        char key = tolower(string[i]);
        if (memo[key])
            continue;
        memo[key] = true;
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (!memo[c])
            return false;
    }

    return true;
}

int main()
{   
    cout << isPangram("we promptly judged antique ivory buckles for the next prize") << endl;
    return 0;
}