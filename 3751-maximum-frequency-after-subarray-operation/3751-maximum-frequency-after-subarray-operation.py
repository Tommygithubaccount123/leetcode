class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        storage = defaultdict(int)
        result = 0

        for num in nums:
            storage[num] = max(storage[num], storage[k]) + 1
            result = max(result, storage[num] - storage[k]) # num of non-k's able to convert
        return storage[k] + result  #maximum number of additional values we can convert to k via one subarray operation