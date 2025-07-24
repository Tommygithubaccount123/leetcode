class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        storage = {}
        n = len(strs)
        out = []
        for i in range(n):
            word = strs[i]
            sort = "".join(sorted(word))
            if sort not in storage:
                storage[sort] = [word]
            else:
                storage[sort].append(word)
        out = []
        for elem in storage:
            out.append(storage[elem])
        return out

