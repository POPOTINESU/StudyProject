from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}

        for index in range(len(nums)):
            diff = target - nums[index]
            if diff in dict:
                return [dict[diff], index]
            dict[nums[index]] = index

        return []
