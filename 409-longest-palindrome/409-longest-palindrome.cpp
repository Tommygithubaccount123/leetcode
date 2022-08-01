class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size()==1){return 1;}
        
        int result=0;
        unordered_map<char,int> storage;
        for (auto i : s){
            storage[i]++;
        }
        for (auto i : storage){
            result += i.second / 2 * 2;
        }
        for (auto i : storage){
            if (i.second % 2 == 1){
                result += 1;
                break;
            }
        }
        
        return result;
    }
};