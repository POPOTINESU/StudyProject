#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

bool isMountain(vector<int> height)
{
    bool isUp = false;
    bool isDown = false;

    int preNumber = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        if (isUp && isDown)
        {
            if (preNumber < height[i])
                return false;
            else if(preNumber == height[i])
                return false;
        }
        else if (isUp)
        {
            if (preNumber > height[i])
                isDown = true;
            else if(preNumber == height[i])
                return false;
        }
        else
        {
            if (preNumber < height[i])
                isUp = true;
            else
                return false;
        }
        preNumber = height[i];
    }
    return isUp && isDown;
}
