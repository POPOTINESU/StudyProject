#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

int minCoinChange(vector<int> coins, int amount)
{
    // 目標金額までの金額を1円単位で最小値を計算しメモする
    vector<int> dp = {amount + 1, amount + 1};

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
                // +1は今回使用するコインを表す
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}
