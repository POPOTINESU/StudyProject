from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)

        dp = [False] * (len(s) + 1)
        dp[0] = True

        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break

        return dp[len(s)]


# 実行例
s = Solution()
print(s.wordBreak("leetcode", ["leet", "code"]))  # 出力: True
print(s.wordBreak("applepenapple", ["apple", "pen"]))  # 出力: True
print(s.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))  # 出力: False
