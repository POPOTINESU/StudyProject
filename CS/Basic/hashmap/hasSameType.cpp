#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

bool hasSameType(string user1, string user2)
{
    map<char, char> charPair;

    if (user1.length() != user2.length())
        return false;

    for (int i = 0; i < user1.length(); i++){
        if (charPair.find(user1[i]) != charPair.end()){
            if(charPair[user1[i]] != user2[i]){
                return false;
            }
        }
        else{
            for(auto & m : charPair){
                if (m.second == user2[i])
                    return false;
            }
            charPair[user1[i]] = user2[i];
        }
    }

    return true;
}