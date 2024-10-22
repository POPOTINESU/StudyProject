#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int binomialCoefficient(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    if (k > n - k)
        k = n - k;

    vector<vector<int>> cache(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        cache[i][0] = 1;
    }

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= k; col++)
        {
            cache[row][col] = cache[row - 1][col - 1] + cache[row - 1][col];
        }
    }
    return cache[n][k];
}

int main()
{
    cout << binomialCoefficient(4, 2) << endl;
    return 0;
}