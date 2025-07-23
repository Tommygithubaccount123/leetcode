class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        sortedIntervals = sorted(intervals)
        out = []
        i=0
        while (i<len(intervals)):
            small = sortedIntervals[i][0]
            big = sortedIntervals[i][1]
            while(i+1 < len(intervals)):
                next_small = sortedIntervals[i+1][0]
                next_big = sortedIntervals[i+1][1]
                if small <= next_big and big >= next_small:
                    big = max(big, next_big)
                    small = min(small, next_small)
                    i += 1
                else:
                    break
            out.append([small, big])
            i += 1

        return out
                



        