class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (auto num : nums){
            total += num;
        }
        if (total % 2 == 1){return false;}
        total /= 2;
        
        vector<vector<bool>> dp(n, vector<bool>(total+1, false));
        
        dp[0][0] = true;
        
        for (int i=1; i<n; i++){
            for (int j=0; j<total+1; j++){
                if (j == 0){
                    dp[i][j] = true;
                    continue;
                }
                if (nums[i] <= j){
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][total];
    }
};