from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_length = len(nums)
        expected_sum = nums_length * (nums_length + 1) // 2
        actual_sum = sum(nums)

        return expected_sum - actual_sum
