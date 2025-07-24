class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ks = nums.count(k)

        glob_max = 0
        for i in range(1,51):
            counter = 0
            cur_max = 0
            for num in nums:
                if num == k:
                    counter -= 1
                if num == i:
                    counter += 1
                counter = max(counter, 0)
                cur_max = max(cur_max, counter)
            glob_max = max(glob_max, cur_max)
        return glob_max + ks