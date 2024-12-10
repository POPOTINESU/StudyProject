class Solution:
    def longestPalindrome(self, s: str) -> str:
        palindrome = "^#" + "#".join(s) + "#$"
        halfPalindrome = [0] * len(palindrome)

        center = 0
        right = 0

        for i in range(1, len(palindrome) - 1):
            if i < right:
                halfPalindrome[i] = min(right - i, halfPalindrome[2 * center - i])

            while (
                palindrome[i + halfPalindrome[i] + 1]
                == palindrome[i - halfPalindrome[i] - 1]
            ):
                halfPalindrome[i] += 1

            if i + halfPalindrome[i] > right:
                center = i
                right = halfPalindrome[i]

        maxPalindromeLength = max(halfPalindrome)
        start_index = (
            halfPalindrome.index(maxPalindromeLength) - maxPalindromeLength
        ) // 2
        return s[start_index : start_index + maxPalindromeLength]
