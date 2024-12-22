class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        dp = []

        for i in range(n + 1):
            if i <= 2:
                dp.append(i)
            else:
                dp.append(dp[i - 1] + dp[i - 2])
        print(dp)
        return dp[n]


s = Solution()
print(s.climbStairs(4))
