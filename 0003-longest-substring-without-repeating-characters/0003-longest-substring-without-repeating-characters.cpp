class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> storage;
        
        int n = s.size();
        int l = 0;
        int r = 0;
        int result = 0;
        
        while (l < n && r < n){
            if (storage.find(s[r]) == storage.end()){
                storage[s[r]]++;
                r++;
                result = max(result, r-l);
            } else {
                storage.erase(s[l]);
                l++;
            }
        }
        return result;
    }
};