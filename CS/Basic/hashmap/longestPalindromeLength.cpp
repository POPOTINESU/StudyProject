#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int longestPalindromeLength(string string)
{
    map<char, int> charOfOccurMap;
    for(char c: string){
        charOfOccurMap[c] ++;
    }

    int result = 0;
    bool hasOdd = false;

    for(auto&m: charOfOccurMap){
        if(m.second % 2 == 0){
            result += m.second;
        }else{
            result += m.second -1;
            hasOdd = true;
        }
    }

    return hasOdd ? result +1 : result; 
}
