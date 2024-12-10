from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        stack = []
        island_count = 0
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == "1":
                    print(row, col)
                    island_count += 1
                    stack.append((row, col))

                    while stack:
                        r, c = stack.pop()
                        for dr, dc in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                            nr = r + dr
                            nc = c + dc
                            if 0 <= nr < len(grid) and 0 <= nc < len(grid[row]):
                                if grid[nr][nc] == "1":
                                    grid[nr][nc] = "0"
                                    stack.append((nr, nc))

        return island_count


s = Solution()

print(
    s.numIslands(
        [
            ["1", "1", "1", "1", "0"],
            ["1", "1", "0", "1", "0"],
            ["1", "1", "0", "0", "0"],
            ["0", "0", "0", "0", "0"],
        ]
    )
)
