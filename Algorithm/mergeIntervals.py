from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return intervals

        intervals.sort(key=lambda x: x[0])
        merged_list = [intervals[0]]

        for i in range(1, len(intervals)):
            last_index = len(merged_list) - 1

            if intervals[i][0] <= merged_list[last_index][1]:
                merged_list[last_index][1] = max(
                    merged_list[last_index][1], intervals[i][1]
                )
            else:
                merged_list.append(intervals[i])

        return merged_list


intervals = []
s = Solution()
print(s.merge(intervals=intervals))
