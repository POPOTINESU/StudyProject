from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        cache = dict()

        for index in range(len(nums)):
            diff = target - nums[index]
            if diff in cache:
                return [cache[diff], index]

            cache[nums[index]] = index

        return []  # when not found
