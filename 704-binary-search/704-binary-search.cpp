class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
    
    int helper(vector<int>& nums, int target, int begin, int end){
        while (begin <= end){
            int mid = (end + begin) / 2;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] < target){
                return helper(nums, target, mid+1, end);
            }
            if (nums[mid] > target){
                return helper(nums, target, begin, mid-1);
            }
        }
        return -1;
    }
};