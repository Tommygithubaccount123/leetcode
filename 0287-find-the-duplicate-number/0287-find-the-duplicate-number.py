class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        slow = 0
        fast = 0

        while (True):
            slow = nums[slow]
            fast = nums[nums[fast]]
            if fast == slow:
                slow = 0
                break
        while (slow != fast):
            slow = nums[slow]
            fast = nums[fast]
        return slow
