class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        heap = []
        for stone in stones:
            heapq.heappush(heap, -1*stone)
        
        while (len(heap) > 1):
            x = -1*heapq.heappop(heap)
            y = -1*heapq.heappop(heap)
            smash = -1*abs(x-y)
            if smash != 0:
                heapq.heappush(heap, smash)
        if not heap:
            return 0
        return -1*heap[0]