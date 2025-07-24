class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        storage = {}
        for num in nums:
            if num in storage:
                storage[num] -= 1
            else:
                storage[num] = -1
        
        heap = []
        for num, freq in storage.items():
            heapq.heappush(heap, (freq,num))
        
        result = []
        for i in range(k):
            freq, num = heapq.heappop(heap)
            result.append(num)
        return result

        