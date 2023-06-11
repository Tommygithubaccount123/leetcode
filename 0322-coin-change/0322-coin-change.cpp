class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
        dp[0][0] = 0;
        coins.push_back(0);
        sort(coins.begin(),coins.end());
        for (int i=0;i<n+1;i++){
            for (int j=0;j<amount+1;j++){
                if (j==0){
                    dp[i][j] = 0;
                }
                if (i==0){
                    continue;
                }
                else if (j-coins[i] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i][j-coins[i]]+1,dp[i-1][j]);
                }
            }
        }
        
        if (dp[n][amount]!=amount+1){
            return dp[n][amount];
        }
        return -1;
    }
};