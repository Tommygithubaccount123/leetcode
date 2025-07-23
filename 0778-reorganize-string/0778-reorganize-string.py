class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        storage = {}
        for i in range(n):
            if s[i] not in storage:
                storage[s[i]] = 1
            else:
                storage[s[i]] += 1
        
        max_heap = []
        for letter in storage:
            freq = -storage[letter]
            heapq.heappush(max_heap, (freq, letter))
        result = ""

        while (len(max_heap) >= 2):
            freq1, letter1 = heapq.heappop(max_heap)
            freq2, letter2 = heapq.heappop(max_heap)
            freq1 *= -1
            freq2 *= -1

            if freq1 > 1:
                freq1 -= 1
                freq1 *= -1
                heapq.heappush(max_heap, (freq1, letter1))
            if freq2 > 1:
                freq2 -= 1
                freq2 *= -1
                heapq.heappush(max_heap, (freq2, letter2))
            
            result += letter1+letter2
        
        if max_heap:
            freq, letter = heapq.heappop(max_heap)
            freq *= -1
            if freq > 1 :
                return ""
            else:
                result += letter
        return result
            
            

 

