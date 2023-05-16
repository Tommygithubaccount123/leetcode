class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        for (int i=0;i<nums.size();i++){
            for (int j=0;j<i;j++){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int maximum = 1;
        for (auto elem : dp){
            if (elem > maximum){
                maximum = elem;
            }
        }
        return maximum;
    }
};