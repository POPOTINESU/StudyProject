from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for index in range(2, len(nums)):
            dp[index] = max(dp[index - 1], dp[index - 2] + nums[index])

        return dp[-1]


s = Solution()
s.rob([1, 3, 1, 3, 100])
