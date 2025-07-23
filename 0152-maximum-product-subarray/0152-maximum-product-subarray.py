class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        big = 1
        small = 1
        glob_max = max(nums)
        for i in range(len(nums)):
            number = nums[i]
            temp = number * big
            big = max(temp, small*number, number)
            small = min(temp, small*number, number)
            glob_max = max(glob_max, big)
        return glob_max

