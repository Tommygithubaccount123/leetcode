class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_max = nums[0]
        glob_max = nums[0]

        for i in range(1,len(nums)):
            number = nums[i]
            cur_max = max(number, cur_max + number)
            glob_max = max(glob_max, cur_max)
        return glob_max