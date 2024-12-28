from collections import Counter
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums_count = Counter(nums)

        return [item[0] for item in nums_count.most_common(k)]


s = Solution()
print(s.topKFrequent([4, 1, -1, 2, -1, 2, 3], 2))
