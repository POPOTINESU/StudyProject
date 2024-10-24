#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> appearTheMost(vector<int> levels)
{
    map<int, int> numberOfOccurrences;
    int maxCount = 0;
    for (int level : levels)
    {
        numberOfOccurrences[level] += 1;
        maxCount = max(maxCount, numberOfOccurrences[level]);
    }

    vector<int> maxList;
    for (const auto& pair : numberOfOccurrences) {
        if (pair.second == maxCount) {
            maxList.push_back(pair.first);
        }
    }
    sort(maxList.begin(), maxList.end());
    return maxList;
}

int main()
{
    vector<int> n = {1, 1, 2, 2, 3, 3, 3, 4, 5, 6};

    vector<int> num = appearTheMost(n);

    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}