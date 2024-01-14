class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> map;
        for (int i=0; i<nums.size()-1; i++){
            if (map.find(nums[i]+nums[i+1]) != map.end()){
                return true;
            }
            map[nums[i]+nums[i+1]]++;
        }
        return false;
    }
};