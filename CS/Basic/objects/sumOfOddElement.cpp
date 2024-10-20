#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int sumOfOddElement(vector<int> arr)
{
    int totalOddElement = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 != 0)
            totalOddElement += arr[i];
    }

    return totalOddElement;
}

int main()
{
    vector<int> arr = {664,657,602,422,608,818,477,822,59,662,769,313,103,58,631};
    cout << sumOfOddElement(arr) << endl;

    return 0;
}