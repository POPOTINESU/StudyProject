from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def fill_in_island(grid: List[List[str]], stack: list[tuple]):
            while stack:
                col, row = stack.pop()
                for dc, dr in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                    new_col, new_row = col + dc, row + dr
                    if (
                        new_col >= 0
                        and new_row >= 0
                        and new_col < len(grid)
                        and new_row < len(grid[0])
                        and grid[new_col][new_row] == "1"
                    ):
                        stack.append((new_col, new_row))
                        grid[new_col][new_row] = "#"

        if not grid:
            return 0
        island_count = 0
        stack = []
        for col in range(len(grid)):
            for row in range(len(grid[0])):
                if grid[col][row] == "1":
                    grid[col][row] = "#"
                    island_count += 1
                    stack.append((col, row))
                    fill_in_island(grid, stack)

        return island_count
