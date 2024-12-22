from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            raise ValueError("nums cannot empty")

        current_sum = nums[0]
        max_sum = nums[0]

        for i in range(1, len(nums)):
            current_sum = max(current_sum + nums[i], nums[i])
            max_sum = max(max_sum, current_sum)

        return max_sum
