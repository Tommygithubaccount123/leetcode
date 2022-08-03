class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> storage;
        for (int i=0;i<nums.size();i++){
            storage[nums[i]]++;
            if (storage[nums[i]]==2){
                return true;
            }
        }
        return false;
    }
};