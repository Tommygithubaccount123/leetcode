class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        
        string prefix = "";
        int length = min(a.size(), b.size());
        for (int i=0; i<length; i++){
            if (a[i] == b[i]){
                prefix += a[i];
            }
            else{
                break;
            }
        }
        return prefix;
    }
};