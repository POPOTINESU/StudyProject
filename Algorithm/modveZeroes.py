from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_index = 0

        for index in range(len(nums)):
            if nums[index] != 0:
                nums[zero_index], nums[index] = nums[index], nums[zero_index]
                zero_index += 1
