#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> rotateByTimes(vector<int> ids, int n)
{
    vector<int> rotateList(ids.size());
    for (int i = 0; i < ids.size(); i++)
    {
        rotateList[(i + n) % ids.size()] = ids[i];
    }
    return rotateList;
}
