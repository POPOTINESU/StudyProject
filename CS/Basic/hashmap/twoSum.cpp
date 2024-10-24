#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> intArr, int sumInt){
    map<int, int> indexPair;
    vector<int> pair;
    for (int i = 0; i < intArr.size(); i++){
        int diff = sumInt - intArr[i];
        if (indexPair.find(diff) != indexPair.end()){
            if (pair.size() == 0){
                pair.push_back(indexPair[diff]);
                pair.push_back(i);
            }
            else if(pair[0] > indexPair[diff]){
                pair[0] = indexPair[diff];
                pair[1] = i;
            }
        }
        if (indexPair.find(intArr[i]) == indexPair.end())
            indexPair[intArr[i]] = i;
    }

    return pair;
}
