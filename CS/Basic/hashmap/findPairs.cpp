#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
using namespace std;

vector<int> findPairs(vector<int> numbers)
{
    map<int, int> ticketPair;
    vector<int> presentNumberList;

    for (int number : numbers)
    {
        if (ticketPair.find(number) != ticketPair.end())
            ticketPair[number]++;
        else
            ticketPair[number] = 1;
    }

    for (auto &count : ticketPair)
    {
        // 同じ数字を持つ生徒が 3 人以上いたら適応外
        if (count.second == 2)
            presentNumberList.push_back(count.first);
    }

    sort(presentNumberList.begin(), presentNumberList.end());

    return presentNumberList;
}
