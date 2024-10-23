#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int searchList(vector<int> numList, int value)
{
    map<int, int> numberEncounter;

    for (int i = 1; i < numList.size(); i++)
    {
        if(numberEncounter[numList[i]] == 0){
            numberEncounter[numList[i]] = i;
        }
    }

    return numberEncounter[value] != 0 ? numberEncounter[value] : -1;
}
