class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> result = {0,0};
        int max_len = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i=n-1; i>=0; i--){
            for (int j=0; j<n; j++){
                if (i > j){
                    continue;
                }
                else if (i==j){
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j]){
                    if ((j-i == 1) || (dp[i+1][j-1])){
                        dp[i][j] = 1;
                        if (j-i > max_len){
                            max_len = j-i;
                            result = {i,j};
                        }
                    }
                }
            }
        }
        string ans;
        for (int i=result[0]; i<=result[1]; i++){
            ans += s[i];
        }
        return ans;
    }
};