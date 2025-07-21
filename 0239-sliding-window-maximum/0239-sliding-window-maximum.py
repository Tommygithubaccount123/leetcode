class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        l = r = 0
        deq = deque()
        result = []
        while (r < len(nums)):
            while deq and nums[deq[-1]] < nums[r]:
                deq.pop()
            deq.append(r)
        
            if deq[0] < l:
                deq.popleft()
            
            if (r+1) >= k:
                result.append(nums[deq[0]])
                l += 1
            r += 1
        return result

