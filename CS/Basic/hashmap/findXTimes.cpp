#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

bool findXTimes(string teams)
{
    map<char, int> gameCount;
    vector<char> keyList;

    for (int i = 0; i < teams.length(); i++)
    {
        if (gameCount.find(teams[i]) != gameCount.end())
            gameCount[teams[i]]++;
        else
        {
            gameCount[teams[i]] = 1;
            keyList.push_back(teams[i]);
        }
    }

    int game = 0;
    for (int key : teams)
    {
        if (game != 0)
        {
            if (gameCount[key] != game)
                return false;
        }
        else
            game = gameCount[key];
    }

    return true;
}
