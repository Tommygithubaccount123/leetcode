class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> storage;
        
        int left = 0;
        int right = 0;
        int n = s.length();
        int count = 0;
        
        while (left < n && right < n){
            if (storage.find(s[right])==storage.end()){
                storage.insert(s[right]);
                right += 1;
                count = max(count, right-left);
            } else {
                storage.erase(s[left]);
                left += 1;
            }
        }
        return count;
    }
};