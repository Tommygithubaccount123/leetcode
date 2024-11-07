class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = dict()
        
        for str in strs:
            sorted_str = ''.join(sorted(str))
            if sorted_str in map:
                map[sorted_str].append(str)
            else:
                map[sorted_str] = [str]
        
        output = []
        for out in map:
            output.append(map[out])
        return output