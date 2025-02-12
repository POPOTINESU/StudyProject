from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total = len(nums)
        expected_sum = total * (total + 1) // 2
        actual_sum = sum(nums)

        return expected_sum - actual_sum
