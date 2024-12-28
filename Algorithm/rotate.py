from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()

        for col in range(len(matrix)):
            for row in range(col):
                matrix[col][row], matrix[col][row] = matrix[col][row], matrix[col][row]


s = Solution()
s.rotate([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
