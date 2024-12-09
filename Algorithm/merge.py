from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals

        intervals = sorted(intervals, key=lambda x: x[0])
        result = [intervals[0]]
        for interval in intervals:
            if result[-1][1] < interval[0]:
                result.append(interval)
            else:
                result[-1][1] = max(interval[1], result[-1][1])

        return result


s = Solution()
print(s.merge([[1, 3], [8, 10], [2, 6], [15, 18]]))
