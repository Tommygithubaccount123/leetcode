class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        l = 0
        r = len(height) - 1
        l_max = height[l]
        r_max = height[r]
        result = 0

        while(l<r):
            if l_max <= r_max:
                l += 1
                l_max = max(l_max, height[l])
                result += l_max - height[l]
            else:
                r -= 1
                r_max = max(r_max, height[r])
                result += r_max - height[r]
        return result
        