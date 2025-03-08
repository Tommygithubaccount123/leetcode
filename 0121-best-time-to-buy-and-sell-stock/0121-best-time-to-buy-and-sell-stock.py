class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        small = 10**4
        profit = 0
        for price in prices:
            small = min(small, price)
            profit = max(profit, price-small)
        return profit