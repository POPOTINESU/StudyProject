class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False

        reversed_num = 0
        tmp_x = x
        while tmp_x != 0:
            reversed_num = reversed_num * 10 + tmp_x % 10
            tmp_x //= 10

        return x == reversed_num
