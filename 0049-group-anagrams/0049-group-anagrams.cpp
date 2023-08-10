class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> storage;
        
        for (auto str : strs){
            string key = str;
            sort(key.begin(), key.end());
            storage[key].push_back(str);
        }
        for (auto lst : storage){
            result.push_back(lst.second);
        }
        return result;
    }
};