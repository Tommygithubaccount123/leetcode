class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        removeFront = nums[1:]
        removeBack = nums[:-1]
        return max(self.helper(removeFront), self.helper(removeBack))

    def helper(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        dp = nums
        dp[1] = max(dp[0], dp[1])
        for i in range(2, n):
            dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        return dp[n-1]
        
