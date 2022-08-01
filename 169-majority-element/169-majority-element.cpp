class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> storage;
        for (int i=0;i<n;i++){
            storage[nums[i]]++;
        }
        
        
        for (auto i : storage){
            if (i.second*2 > n){
                return i.first;
            }
        }
        return 0;
    }
};