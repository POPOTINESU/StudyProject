from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        def isValid(row, col):
            return 0 <= row < rows and 0 <= col < cols and grid[row][col] == "1"

        islands = 0
        stack = []
        rows = len(grid)
        cols = len(grid[0])

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    stack.append((row, col))
                    islands += 1
                while stack:
                    r, c = stack.pop()
                    grid[r][c] = "0"
                    for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                        if isValid(r + dr, c + dc):
                            stack.append((r + dr, c + dc))

        return islands


s = Solution()
print(
    s.numIslands(
        [
            [
                "1",
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
            ],
            [
                "1",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "1",
                "0",
            ],
            [
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
            ],
            [
                "0",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
            ],
            [
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
            ],
            [
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
            ],
            [
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
            ],
            [
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "1",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
                "0",
                "1",
                "1",
                "1",
                "0",
            ],
            [
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
            ],
            [
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
            ],
            [
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
            ],
            [
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
                "0",
                "1",
                "1",
                "1",
                "0",
                "1",
                "1",
                "0",
                "0",
            ],
            [
                "1",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
            ],
            [
                "0",
                "1",
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "1",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
            ],
            [
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
            ],
            [
                "1",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
            ],
            [
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
            ],
            [
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "0",
                "1",
                "0",
                "1",
                "0",
                "1",
                "1",
                "1",
                "1",
                "0",
                "0",
            ],
            [
                "0",
                "1",
                "0",
                "0",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "1",
                "0",
                "1",
                "0",
                "0",
                "1",
                "0",
                "0",
                "1",
                "1",
            ],
            [
                "0",
                "0",
                "0",
                "0",
                "0",
                "0",
                "1",
                "1",
                "1",
                "1",
                "0",
                "1",
                "0",
                "0",
                "0",
                "1",
                "1",
                "0",
                "0",
                "0",
            ],
        ]
    )
)
