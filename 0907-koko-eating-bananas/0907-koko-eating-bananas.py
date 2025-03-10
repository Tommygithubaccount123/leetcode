class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = max(piles)
        while (low <= high):
            rate = (high - low) // 2 + low
            time = h
            for i in range(len(piles)):
                time -= int(math.ceil(piles[i] / rate))
            if (time < 0):
                low = rate + 1
            else:
                high = rate - 1
        return low

        