#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int getMinSteps(int n)
{
    vector<int> dp(n + 1, n + 1);

    // 1になるまでのステップである
    // 0も条件で1にはならない
    dp[0] = 0, dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[n];
}

int main()
{
    cout << getMinSteps(10) << endl;
}