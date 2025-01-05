from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n + 1)]
        dp[0] = [""]

        for i in range(1, n + 1):
            current_set = set()

            for j in range(i):
                for left in dp[j]:
                    for right in dp[i - 1 - j]:
                        current_set.add(f"({left}){right}")

            dp[i] = list(current_set)

        return dp[n]


# テスト
s = Solution()
print(s.generateParenthesis(n=3))
