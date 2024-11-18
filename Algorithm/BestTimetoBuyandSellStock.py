from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        min_prices = 10001
        max_profit = 0

        for i in range(len(prices)):
            if min_prices > prices[i]:
                min_prices = prices[i]
            else:
                max_profit = max(max_profit, prices[i] - min_prices)

        return max_profit


s = Solution()
print(s.maxProfit([1, 2]))
