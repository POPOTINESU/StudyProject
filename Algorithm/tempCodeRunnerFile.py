       """
        Do not return anything, modify matrix in-place instead.
        """
        next_matrix = matrix.copy()

        for col in range(len(matrix)):
            for row in range(len(matrix[0])):
                target = matrix[col][row]
                next_matrix[row][len(matrix) - col - 1] = target
        
        matrix = next_matrix


s = Solution()