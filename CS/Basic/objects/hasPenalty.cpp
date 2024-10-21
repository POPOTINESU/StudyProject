#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool hasPenalty(vector<int> records)
{
    int maxRecord = 0;
    for (int i = 0; i < records.size(); i++)
    {
        if (records[i] < maxRecord)
            return true;

        maxRecord = max(maxRecord, records[i]);
    }
    return false;
}
