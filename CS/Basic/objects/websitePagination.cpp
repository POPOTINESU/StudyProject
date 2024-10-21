#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<string> websitePagination(vector<string> urls, int pageSize, int page)
{
    int initalIndex = pageSize * (page - 1);
    int lastIndex = urls.size()-1;

    vector<string> pagination;

    if (lastIndex - initalIndex < pageSize)
    {
        for (int i = initalIndex; i <= lastIndex; i++)
        {
            pagination.push_back(urls[i]);
        }
    }
    else
    {
        for (int i = 0; i < pageSize; i++)
        {
            pagination.push_back(urls[i + initalIndex]);
        }
    }
    return pagination;
}
