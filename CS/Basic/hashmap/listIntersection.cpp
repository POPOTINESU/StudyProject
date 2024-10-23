#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> listIntersection(vector<int> targetList, vector<int> searchList)
{
    map<int, bool> encounter;
    map<int, bool> setNum;
    vector<int> intersection;

    for(int i = 0; i < searchList.size(); i++){
        encounter[searchList[i]] = true;
    }

    for(int i = 0; i < targetList.size(); i++){
        if(encounter[targetList[i]] && !setNum[targetList[i]]){
            intersection.push_back(targetList[i]);
            setNum[targetList[i]] = true;
        }
    }
    sort(intersection.begin(), intersection.end());
    return intersection;
}
