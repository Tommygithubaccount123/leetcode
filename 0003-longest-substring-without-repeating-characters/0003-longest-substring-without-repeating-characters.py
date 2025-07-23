class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        ans = 0
        l = r = 0
        storage = {}
        while (r<n):
            letter = s[r]
            if letter in storage:
                del storage[s[l]]
                l += 1
            else:
                storage[letter] = 1
                r += 1
                ans = max(ans, r-l)
        return ans
                