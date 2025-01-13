class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_count = {}
        for c in s:
            s_count[c] = s_count.get(c, 0) + 1

        for c in t:
            target = s_count.get(c, 0)
            if target == 0:
                return False
            else:
                s_count[c] -= 1

        return True
