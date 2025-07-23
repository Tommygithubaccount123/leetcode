class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        cur_max = prices[0]
        glob_max = 0
        for i in range(1,len(prices)):
            price = prices[i]
            cur_max = min(price, cur_max)
            glob_max = max(glob_max, price-cur_max)
        return glob_max