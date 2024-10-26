#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> insertionSort(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i ++){
        int currentValue = arr[i];

        for (int j = i -1; j >= 0; j --){
            if (currentValue <= arr[j]){
                arr[j+1] = arr[j];
                arr[j] = currentValue;
            }else {
                break;
            }
        }
    }

    return arr;
}
