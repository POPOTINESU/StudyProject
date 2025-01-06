from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)

        for right in range(n - 2, -1, -1):
            if nums[right] < nums[right + 1]:
                for swap in range(n - 1, right, -1):
                    if nums[swap] > nums[right]:
                        nums[swap], nums[right] = nums[right], nums[swap]
                        break
                nums[right + 1 :] = sorted(nums[right + 1 :])
                return

        nums.sort()


s = Solution()

nums1 = [1, 2, 3]

s.nextPermutation(nums1)
print(nums1)
assert [1, 3, 2] == nums1

# nums2 = [3, 2, 1]
# s.nextPermutation(nums2)
# print(nums2)
# assert [1, 2, 3] == nums2

# nums3 = [1, 1, 5]
# s.nextPermutation(nums3)
# print(nums3)
# assert [1, 5, 1] == nums3
