class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        int n = dp.size();
        if (n == 1){return nums[0];}
        if (n == 2){return max(nums[0],nums[1]);}
        dp[1] = max(nums[0],nums[1]);
        
        for (int i=2; i<n; i++){
            dp[i] = max(dp[i-2] + dp[i], dp[i-1]);
        }
        return dp[n-1];
    }
};