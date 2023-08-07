class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums){
            sum += num;
        }
        if (sum % 2 == 1){return false;}
        int target = sum / 2;
        
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        dp[0][0] = true;
        
        for (int i=1; i<n; i++){
            for (int j=0; j<target+1; j++){
                if (j==0){
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};