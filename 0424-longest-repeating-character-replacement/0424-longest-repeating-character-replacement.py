class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        l = 0
        r = 0
        longest = 0
        freq = DefaultDict(int)
        maxFreq = 0
        while (r < n):
            freq[s[r]] += 1
            maxFreq = max(maxFreq, freq[s[r]])
            length = r - l + 1
            swapsNeeded = length - maxFreq
            if swapsNeeded <= k:
                longest = max(longest, length)
                # r += 1
            else:
                freq[s[l]] -= 1
                l += 1
            r += 1
        return longest