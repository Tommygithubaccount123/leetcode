class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> storage;
        int start_index = 0;
        int count = 0;
        for (int i=0; i<s.length(); i++){
            if (storage.find(s[i])==storage.end()){
                storage[s[i]]++;
                count = max(count, 1 + i - start_index);
            } else {
                storage.erase(storage.find(s[start_index]));
                i--;
                start_index++;
            }
        }
        return count;
    }
};