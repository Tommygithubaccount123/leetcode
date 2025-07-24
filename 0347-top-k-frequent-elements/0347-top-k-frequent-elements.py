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
                storage[num] += 1
            else:
                storage[num] = 1
        
        heap = []
        for num, freq in storage.items():
            if heap and len(heap) >= k:
                tempFreq, tempNum = heap[0]
                if tempFreq < freq:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (freq,num))
            else:
                heapq.heappush(heap, (freq,num))
        
        result = []
        while (heap):
            freq, num = heapq.heappop(heap)
            result.append(num)
        return result

        