class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        n = len(s)

        substr = ""
        start_index = 0
        out = 0
        while (l<n):
            if s[l] not in substr:
                substr +=  s[l]
                out = max(out, len(substr))
                l += 1
            else:
                start_index += 1
                l = start_index
                substr = ""
        return out

            