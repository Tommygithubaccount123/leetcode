class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        storage = {}
        for num in nums:
            if num not in storage:
               storage[num] = 1
            else:
                storage[num] += 1
        ks = 0
        if k in storage:
            ks = storage[k]

        glob_max = 0
        for i in range(1,51):
            if i == k:
                continue
            cur_max = counter = 0
            for num in nums:
                if i == num:
                    counter += 1
                elif num == k:
                    counter -= 1
                cur_max = max(cur_max, counter)
                counter = max(counter , 0)
            glob_max = max(glob_max, cur_max)
        return glob_max + ks


            