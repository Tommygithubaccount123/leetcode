class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        sortedIntervals = sorted(intervals)
        out = [sortedIntervals[0]]

        i = 1
        while (i < len(intervals)):
            curEndBig = out[-1][1]
            new_interval = sortedIntervals[i]
            if curEndBig >= new_interval[0]:
                out[-1][1] = max(out[-1][1], new_interval[1])
            else:
                out.append(new_interval)
            i += 1
        return out