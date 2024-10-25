#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int longestSubstringLength(string password)
{
    map<char, int> noDuplicateCount;
    int maxNoDuplicate = 0;
    int start = 0;

    for (int current = 0; current < password.length(); current++)
    {   
        if(noDuplicateCount.find(password[current]) != noDuplicateCount.end() && noDuplicateCount[password[current]] >= start){
            start = noDuplicateCount[password[current]] + 1;
        }

        maxNoDuplicate = max(maxNoDuplicate, current - start + 1);
        noDuplicateCount[password[current]] = current;
    }

    return maxNoDuplicate;
}
