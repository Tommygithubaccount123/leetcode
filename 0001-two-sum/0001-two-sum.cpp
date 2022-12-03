class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storage;
        for (int i=0; i<nums.size(); i++){
            if (storage.find(target - nums[i]) != storage.end()){
                return {i, storage[target - nums[i]]};
            }
            storage[nums[i]] = i;
        }
        return {};
    }
};