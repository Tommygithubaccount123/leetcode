class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> storage;
        storage[0] = 1;
        
        int count = 0;
        int sum = 0;
        for (auto num : nums){
            sum += num;
            if (storage.find(sum-k) != storage.end()){
                count += storage[sum-k];   
            }
            storage[sum] += 1;
        }
        return count;
    }
};