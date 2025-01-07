class Solution:
    """
    myPow
    """

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        half = self.myPow(x, abs(n) // 2)
        if n % 2 == 0:
            result = half * half
        else:
            result = half * half * x

        return result if n > 0 else 1 / result


s = Solution()
print(s.myPow(2.00, -20))
