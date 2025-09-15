class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append((timestamp, value))
        # print(self.map)
    
    def get(self, key: str, timestamp: int) -> str:
        values = self.map[key]
        l, r = 0, len(values) - 1
        while l <= r:
            m = l + (r - l) // 2
            if values[m][0] <= timestamp:
                l = m + 1
            else:
                r = m - 1
        
        return values[r][1] if r >= 0 else ""