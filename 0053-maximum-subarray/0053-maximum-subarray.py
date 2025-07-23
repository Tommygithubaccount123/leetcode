class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_max = nums[0]
        global_max = nums[0]
        for i in range(1,len(nums)):
            cur_max = max(nums[i], cur_max+nums[i])
            global_max = max(global_max, cur_max)
        return global_max
        