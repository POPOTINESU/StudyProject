from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        memo = {0: 1}
        sum = 0

        for num in nums:
            sum += num
            diff = sum - k

            if diff in memo:
                count += memo[diff]

            memo[sum] = memo[sum] + 1 if sum in memo else 1

        return count


s = Solution()
print(s.subarraySum([1, 1, 1], 1))
