class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size()==0 || amount==0){return 0;}
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for (int i=1; i<=amount; i++){
            // dp[i] = amount + 1;
            for (int j=0; j<coins.size(); j++){
                if (coins[j] <= i){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]); 
                } else{
                    break; 
                }
            }
        }
        return dp[amount] < amount + 1 ? dp[amount] : -1;
    }
};