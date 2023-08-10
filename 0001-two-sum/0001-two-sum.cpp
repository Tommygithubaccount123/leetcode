class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> storage;
        int diff;
        for (int i=0; i<nums.size(); i++){
            diff = target - nums[i];
            if (storage.find(diff) != storage.end()){
                return {storage[diff],i};
            }
            storage[nums[i]] = i;
        }
        return {};
    }
};