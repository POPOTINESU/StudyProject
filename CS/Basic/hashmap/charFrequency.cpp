#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
using namespace std;

vector<string> charFrequency(string message){
    //　条件よりすべて小文字である
    map<char, int> charFrequencyMap;
    for(int i = 0; i < message.length(); i++){
        if (message[i] == ' ') continue;
        charFrequencyMap[message[i]] +=1;
    }

    vector<string> result;

    for(auto m : charFrequencyMap){

        string key(1, m.first);
        string ans = key + " : " + to_string(m.second);
        result.push_back(ans);
    }

    return result;
} 