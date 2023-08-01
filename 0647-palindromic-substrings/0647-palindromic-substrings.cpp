class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i=n-1; i>=0; i--){
            for (int j=0; j<n; j++){
                if (i > j){
                    continue;
                }
                else if (i==j){
                    dp[i][j] = 1;
                    total++;
                }
                else if (s[i]==s[j]){
                    if ((j-i == 1) || (dp[i+1][j-1])){
                        dp[i][j] = 1;
                        total++;
                    }
                }
            }
        }
        return total;
    }
};