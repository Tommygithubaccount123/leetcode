class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 1:
            return 1
        ans = 0
        i = j = 0
        while (i<n):
            storage = {}
            j=i
            while (j<n):
                letter = s[j]
                if letter in storage:
                    ans = max(ans, j-i)
                    break
                storage[letter] = 1
                j += 1
                if j == n:
                    ans = max(ans, j-i)
            i += 1
        return ans
                