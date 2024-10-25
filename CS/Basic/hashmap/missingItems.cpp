#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

vector<int> missingItems(vector<int> listA, vector<int> listB){
    vector<int> addCartList;
    map<int, bool> currentCartMap;

    for(int bCartItem: listB){
        currentCartMap[bCartItem] = true;
    }

    for (int aCartItem: listA){
        if(!currentCartMap[aCartItem]){
            addCartList.push_back(aCartItem);
        }
    }

    return addCartList;
}
