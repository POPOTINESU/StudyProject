#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int videosToWatch(vector<int> time, int dailyGoal)
{

    // 格納された順に見るものとする
    int totalTime = 0;
    for (int i = 0; i < time.size(); i++)
    {
        totalTime += time[i];

        if (totalTime >= dailyGoal)
        {
            return i + 1;
        }
    }

    return -1;
}
