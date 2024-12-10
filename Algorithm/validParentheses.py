class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 0 or len(s) % 2 == 1:
            return False

        stack = []
        parentheses_pair = {"(": ")", "[": "]", "{": "}"}
        close_parentheses = (")", "}", "]")

        for c in s:
            if not stack and c in close_parentheses:
                return False
            elif c in close_parentheses:
                pop_c = stack.pop()
                if c != parentheses_pair[pop_c]:
                    return False
                continue
            stack.append(c)

        return True if not stack else False


s = Solution()
print(s.isValid("([])"))
