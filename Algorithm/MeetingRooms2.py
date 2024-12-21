import heapq
from typing import List


class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[0])

        meeting_rooms = []
        heapq.heappush(meeting_rooms, intervals[0][1])

        for i in intervals[1:]:
            if i[0] >= meeting_rooms[0]:
                heapq.heappop(meeting_rooms)

            heapq.heappush(meeting_rooms, i[1])

        return len(meeting_rooms)

s = Solution()
print(s.minMeetingRooms([[2, 15], [36, 45], [9, 29], [16, 23], [4, 9]]))
