class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> storage;
        for (auto& i : nums){
            if (storage.find(i)!=storage.end()){
                return true;
            }
            storage[i] = true;
        }
        
        return false;
    }
};