class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0){return true;}
        int start = 0;
        int end = s.size()-1;
        while (start<end){
            if (!isalnum(s[start])){
                start += 1;
                continue;
            }
            if (!isalnum(s[end])){
                end -= 1;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start += 1;
            end -= 1;
        }
        return true;
    }
};