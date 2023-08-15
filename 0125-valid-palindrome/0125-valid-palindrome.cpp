class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if (s[l] == ' ' || !isalnum(s[l])){
                l++;
            }
            else if (s[r] == ' ' || !isalnum(s[r])){
                r--;
                continue;
            }
            else if (tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};