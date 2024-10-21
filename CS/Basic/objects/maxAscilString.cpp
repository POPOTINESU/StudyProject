#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int maxAscilString(vector<string> stringList)
{
    int maxString = 0;
    int maxIndex = 0;
    for (int i = 0; i < stringList.size(); i++)
    {
        int charTotal = 0;
        for (int c = 0; c < stringList[i].length(); c++)
        {
            charTotal += int(stringList[i][c] - '0');
        }

        if (charTotal > maxString)
        {
            maxString = charTotal;
            maxIndex = i;
        }
    }

    return maxIndex;
}