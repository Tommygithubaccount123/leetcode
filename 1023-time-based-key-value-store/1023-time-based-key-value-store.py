class TimeMap:

    def __init__(self):
        self.storage = defaultdict(list) # {"foo" : [(bar,1), (bar2, 4)...]}

    def set(self, key: str, value: str, timestamp: int) -> None:
        pair = (value, timestamp)
        self.storage[key].append(pair)

    def get(self, key: str, timestamp: int) -> str:
        if not self.storage[key]:
            return ""
        times = self.storage[key]
        l = 0
        r = len(times) - 1
        mid = 0
        best_guess = ""
        while (l<=r):
            mid = (r-l)//2 + l
            guess = times[mid]
            if guess[1] <= timestamp:
                l = mid + 1
                best_guess = guess[0]
            elif guess[1] > timestamp:
                r = mid - 1
        return best_guess


        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)