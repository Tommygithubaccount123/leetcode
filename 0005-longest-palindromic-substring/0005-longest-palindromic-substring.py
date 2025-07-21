class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        if n == 1:
            return s
        dp = [[False for j in range(n+1)] for i in range(n+1)]

        start = 0
        longest = 0
        for i in range(n-1,-1,-1):
            for j in range(1,n):
                if i==j:
                    dp[i][j] = True
                if i > j:
                    continue
                if s[i] == s[j]:
                    if j-i == 1 or dp[i+1][j-1]:
                        dp[i][j] = True
                        if j-i > longest:
                            longest = j-i
                            start = i
        return s[start:start+longest+1]