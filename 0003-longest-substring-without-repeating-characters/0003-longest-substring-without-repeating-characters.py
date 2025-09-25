class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        storage = {}
        l = 0
        r = 0
        out = 0
        while r < len(s):
            if s[r] in storage:
                del storage[s[l]]
                l += 1
            else:
                storage[s[r]] = 1
                r += 1
                out = max(out, r-l)
        return out