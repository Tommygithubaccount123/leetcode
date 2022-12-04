class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return False
        y = str(x)
        r = y[::-1]
        return r == y