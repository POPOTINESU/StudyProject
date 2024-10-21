#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

bool canMakeTargetVal(vector<int> arr, int target){
    // ハッシュマップは配列の練習なので使わない
    for (int i = 0; i <  arr.size(); i++){
        for (int j = i+1; j < arr.size(); j++){
            if (target == arr[i] + arr[j]) return true;
        }
    }
    return false;
}