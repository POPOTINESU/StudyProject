class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {")": "(", "]": "[", "}": "{"}

        for char in s:
            if char in pairs.values():
                stack.append(char)
            else:
                if not stack or stack.pop() not in pairs[char]:
                    return False

        return not stack


s = Solution()
s.isValid("()")
