class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False for j in range(n)] for i in range(n)]
        longest = 0
        start = 0
        for i in range(n-1,-1,-1):
            for j in range(n):
                if i==j:
                    dp[i][j] = True
                    continue
                if i>j:
                    continue
                if s[i]==s[j]:
                    if dp[i+1][j-1] or (j-i == 1):
                        dp[i][j] = True
                        if j-i > longest:
                            longest = j-i
                            start = i
        return s[start:start+longest+1]
        
