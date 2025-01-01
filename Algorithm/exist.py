from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False
        stack = []
        for col in range(len(board)):
            for row in range(len(board[0])):
                word_index = 0
                if board[col][row] == word[word_index]:
                    word_index += 1
                    prev_place = (col, row)
                    stack.append((col, row))

                while not len(stack) == 0 and word_index != len(word):
                    current_place = stack.pop()

                    for place in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                        dc = current_place[0] + place[0]
                        dr = current_place[1] + place[1]

                        if (
                            dc >= 0
                            and dc < len(board)
                            and dr >= 0
                            and dr < len(board[0])
                            and board[dc][dr] == word[word_index]
                            and prev_place != (dc, dr)
                        ):
                            word_index += 1
                            prev_place = (current_place[0], current_place[1])
                            stack.append((dc, dr))
                            break

                if word_index == len(word):
                    return True

        return False


s = Solution()
print(s.exist([["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]], "AAB"))
