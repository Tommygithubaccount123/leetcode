class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> storage;
        for (auto i : nums){
            storage[i]++;
            if (storage[i]==2){
                return true;
            }
        }
        return false;
    }
};