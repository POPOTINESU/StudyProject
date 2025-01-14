from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        total_profit = 0
        for day in range(1, len(prices)):
            if prices[day] > prices[day-1]:
                total_profit += prices[day] - prices[day-1]
        
        return total_profit



s = Solution()
print(s.maxProfit([1,2,3,4,5]))
