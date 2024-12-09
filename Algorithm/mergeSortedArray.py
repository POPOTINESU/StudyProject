from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if len(nums1) != m + n:
            raise ValueError("nums1 length must match m+n")

        replace_index = len(nums1) - 1
        for n in nums2:
            nums1[replace_index] = n
            replace_index -= 1

        nums1.sort()


s = Solution()
s.merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3)
