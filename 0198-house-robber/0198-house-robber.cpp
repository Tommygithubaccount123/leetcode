class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        int n = nums.size();
        if (n == 1) {return nums[0];}
        if (n == 2) {return nums[0] > nums[1] ? nums[0] : nums[1];}
        dp[1] = max(dp[0], dp[1]);
        for (int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};