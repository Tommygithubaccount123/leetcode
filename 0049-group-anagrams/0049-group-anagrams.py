class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        storage = dict()

        for word in strs:
            key = ''.join(sorted(word))
            if key not in storage:
                storage[key] = [word]
            else:
                storage[key].append(word)
        
        out = []
        for elem in storage:
            out.append(storage[elem])
        return out