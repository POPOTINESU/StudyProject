#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

string maxOfPairSum(vector<int> arr1, vector<int> arr2, int x)
{
    int maxPair = NULL;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            int total = arr1[i] + arr2[j];
            if (x > total)
            {   
                if (!maxPair)
                    maxPair = total;
                maxPair = max(maxPair, total);
            }
        }
    }

    if (!maxPair)
        return "no pair";

    return to_string(maxPair);
}