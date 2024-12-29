from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reachable = 0

        for index, jump in enumerate(nums):
            if index > max_reachable:
                return False

            max_reachable = max(max_reachable, index + jump)

            if max_reachable >= len(nums) - 1:
                return True
        
        return False


s = Solution()
print(
    s.canJump(
        nums=[
            8,
            2,
            4,
            4,
            4,
            9,
            5,
            2,
            5,
            8,
            8,
            0,
            8,
            6,
            9,
            1,
            1,
            6,
            3,
            5,
            1,
            2,
            6,
            6,
            0,
            4,
            8,
            6,
            0,
            3,
            2,
            8,
            7,
            6,
            5,
            1,
            7,
            0,
            3,
            4,
            8,
            3,
            5,
            9,
            0,
            4,
            0,
            1,
            0,
            5,
            9,
            2,
            0,
            7,
            0,
            2,
            1,
            0,
            8,
            2,
            5,
            1,
            2,
            3,
            9,
            7,
            4,
            7,
            0,
            0,
            1,
            8,
            5,
            6,
            7,
            5,
            1,
            9,
            9,
            3,
            5,
            0,
            7,
            5,
        ]
    )
)
