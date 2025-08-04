class TimeMap:

    def __init__(self):
        self.storage = defaultdict(list) # {key : [(val, time)...], ...}

    def set(self, key: str, value: str, timestamp: int) -> None:
        pair = (value, timestamp)
        self.storage[key].append(pair)

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.storage:
            return ""
        values = self.storage[key]
        l = 0
        r = len(values) - 1
        ans = ""
        while (l<=r):
            mid = (r-l) // 2 + l
            if values[mid][1] <= timestamp:
                ans = values[mid][0]
                l = mid + 1
            else:
                r = mid - 1
        return ans


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)