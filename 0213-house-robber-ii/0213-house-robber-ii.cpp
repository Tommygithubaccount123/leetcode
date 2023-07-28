class Solution {
public:
    int rob(vector<int>& nums){
        if (nums.size() == 1) {return nums[0];}
        vector<int> removeBack = nums;
        removeBack.pop_back();
        vector<int> removeFront = nums;
        removeFront.erase(removeFront.begin());
        return max(robHelp(removeBack), robHelp(removeFront));
    }
    
    int robHelp(vector<int>& nums) {
        //dp[i] stores max profit up to house i
        vector<int> dp = nums;
        int n = nums.size();
        
        //base cases
        if (n == 1) {return nums[0];}
        if (n == 2) {return nums[0] > nums[1] ? nums[0] : nums[1];}
        dp[1] = max(dp[0], dp[1]);
        
        //fill dp table
        for (int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};