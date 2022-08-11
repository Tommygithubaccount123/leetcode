class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int> storage;
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            int other = nums[i] - diff;
            int other2 = nums[i] - diff * 2;
            if (storage.find(other)!=storage.end() && storage.find(other2)!=storage.end()){
                ans += 1;
            }
            storage[nums[i]]++;
        }
        
        return ans;
    }
};