class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_big = 0;
        int big = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            cur_big = max(nums[i], nums[i] + cur_big);
            big = max(big, cur_big);
        }
        return big;
    }
};