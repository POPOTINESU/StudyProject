class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged_string = "".join(a + b for a, b in zip(word1, word2))

        return merged_string + word1[len(word2) :] + word2[len(word1) :]


s = Solution()
print(s.mergeAlternately(word1="abc", word2="pqr"))
