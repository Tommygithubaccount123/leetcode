class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> storage;
        for (int i=0;i<n;i++){
            storage[nums[i]]++;
            if (storage[nums[i]]>n/2){
                return nums[i];
            }
        }
        return 0;
    }
};