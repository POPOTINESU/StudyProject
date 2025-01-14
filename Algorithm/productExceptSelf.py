from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n

        left, right = 1, 1

        for i in range(n):
            answer[i] = left
            left *= nums[i]

        for i in range(n - 1, -1, -1):
            answer[i] *= right
            right *= nums[i]

        return answer


s = Solution()
print(s.productExceptSelf([1, 2, 3, 4]))