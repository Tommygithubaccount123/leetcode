#KADANES ALGO
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (!n){
            return 0;
        }
        int out = INT_MIN;
        int sum = 0;
        for (int i=0; i<n; i++){
            sum = max(nums[i], sum+nums[i]);
            out = max(out,sum);
        }
         
        return out;
    }
};