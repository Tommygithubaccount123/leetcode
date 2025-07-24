class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        big = 10**9
        small = 1
        ans = big
        while (small <= big):
            k = (big - small) // 2 + small
            time = h
            for pile in piles:
                time -= math.ceil(pile / k)
            if time < 0:
                small = k+1
            else:
                big = k-1
        return small
                