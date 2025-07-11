class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        storage = dict()

        for num in nums:
            if num not in storage:
                storage[num] = 1
        
        ans = 0
        for num in storage:
            cur_len = 1
            cur_num = num + 1
            if num-1 not in storage:
                while cur_num in storage:
                    cur_len += 1
                    cur_num += 1
            ans = max(ans, cur_len)
        return ans