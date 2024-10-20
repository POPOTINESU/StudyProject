#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> evenRange(int a, int b)
{
    vector<int> doubleNums;

    for (int i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            doubleNums.push_back(i);
    }

    if (doubleNums.size() == 1)
    {
        cout << "[]" << endl;
    }
    else
    {
        cout << "[";
        for (int i = 0; i < doubleNums.size(); i++)
        {
            cout << doubleNums[i];

            if (i != doubleNums.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return doubleNums;
}

int main()
{
    evenRange(10, 20);
    return 0;
}