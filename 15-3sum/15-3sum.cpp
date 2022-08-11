class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size(); i++){
            int low = i + 1;
            int high = nums.size() - 1;
            int sum = 0 - nums[i];
            if (i>0 && nums[i]==nums[i-1]){continue;}
            while (low<high){
                if (nums[low]+nums[high]==sum){
                    ans.push_back({nums[low], nums[high], nums[i]});
                    while (low < high && nums[low+1]==nums[low]){
                        low += 1;
                    }
                    while (high > low && nums[high]==nums[high-1]){
                        high -= 1;
                    }
                    low += 1;
                    high -= 1;
                } else if (nums[low]+nums[high] > sum){
                    high -= 1;
                } else {
                    low += 1;
                }
            }
        }
        
        return ans;
    }
};