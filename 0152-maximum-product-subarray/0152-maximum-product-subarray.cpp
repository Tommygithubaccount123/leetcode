class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> big(nums.size());
        vector<int> small(nums.size());
        big[0] = nums[0];
        small[0] = nums[0];
        for (int i=1;i<nums.size();i++){
            // if(nums[i] < 0) {
            //     big[i] = max(small[i-1]*nums[i],nums[i]);
            //     small[i] = min(big[i-1]*nums[i],nums[i]);
            // } else {
            //     big[i] = max(big[i-1]*nums[i],nums[i]);
            //     small[i] = min(small[i-1]*nums[i],nums[i]);
            // }
            big[i] = max(big[i-1]*nums[i], max(small[i-1]*nums[i],nums[i]));
            small[i] = min(small[i-1]*nums[i], min(big[i-1]*nums[i],nums[i]));
        }
        return *max_element(big.begin(),big.end());
    }
};