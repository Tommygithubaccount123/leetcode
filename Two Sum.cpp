class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> x;
        for (int i = 0; i<nums.size(); i++){
            if ((x.find(target-nums[i])) != x.end()){
                return {x[target-nums[i]],i};
            }
            x[nums[i]] = i;       
        }
        return {-1};
    }
};