class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> found;
        for (int i=0; i<nums.size(); i++){
            if (found.find(nums[i]) != found.end()){
                return true;
            }
            found[nums[i]] = 1;
        }
        return false;
    }
};