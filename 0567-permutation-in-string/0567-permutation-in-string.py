class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        if n1 > n2:
            return False
        storage1 = defaultdict(int)
        storage2 = defaultdict(int)
        for s in s1:
            storage1[s] += 1
        for i in range(n1):
            storage2[s2[i]] += 1

        l=0
        r=n1-1
        while r < n2-1:
            if storage1 == storage2:
                return True
            storage2[s2[r+1]] += 1
            storage2[s2[l]] -= 1
            if storage2[s2[l]] == 0:
                del storage2[s2[l]]
            l += 1
            r += 1
        return storage1 == storage2