class Solution:
    def longestPalindrome(self, s: str) -> str:
        def preProcess(s: str) -> str:
            return "^#" + "#".join(s) + "#$"

        palindrome = preProcess(s)
        halfPalindrome = [0] * len(palindrome)

        center = 0
        right = 0

        for i in range(1, len(palindrome) - 1):
            if i < right:
                halfPalindrome[i] = min(right - i, halfPalindrome[2 * center - i])

            # centerごとの回文半径を記録する
            while (
                palindrome[i + halfPalindrome[i] + 1]
                == palindrome[i - halfPalindrome[i] - 1]
            ):
                halfPalindrome[i] += 1

            if i + halfPalindrome[i] > right:
                center = i
                right = halfPalindrome[i]Z

        maxPalindromeLength = max(halfPalindrome)
        startIndex = (
            halfPalindrome.index(maxPalindromeLength) - maxPalindromeLength
        ) // 2

        return s[startIndex : startIndex + maxPalindromeLength]


s = Solution()
print(s.longestPalindrome("babad"))
