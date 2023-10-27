class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int i=1; i<amount+1; i++){
            for (int coin=0; coin<coins.size(); coin++){
                if (i >= coins[coin]){
                    dp[i] = min(dp[i-coins[coin]]+1, dp[i]);
                }
            }
        }
        if (dp[amount] == amount+1){
            return -1;
        }
        return dp[amount];
    }
};