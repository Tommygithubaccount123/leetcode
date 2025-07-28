class Solution:
    def reorganizeString(self, s: str) -> str:
        storage = defaultdict(int)
        for i in s:
            storage[i] += 1
        
        heap = []
        for key, value in storage.items():
            pair = [-value, key]
            heapq.heappush(heap, pair)
        
        out = ""
        while len(heap) > 1:
            first = heapq.heappop(heap)
            second = heapq.heappop(heap)

            out += first[1] + second[1]
            first[0] += 1
            second[0] += 1
            if -first[0] > 0:
                heapq.heappush(heap, first)
            if -second[0] > 0:
                heapq.heappush(heap, second)
        
        if heap:
            last = heapq.heappop(heap)
            if -last[0] > 1:
                return ""
            return out + last[1]
        return out
            

