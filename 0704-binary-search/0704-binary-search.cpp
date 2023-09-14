class Solution {
public:
    int helper(vector<int>&nums, int l, int r, int target){
        if (l > r){return -1;}
        
        int mid = (l + r) / 2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] > target){
            return helper(nums, l, mid-1, target);
        } 
        else{
            return helper(nums, mid+1, r, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
    }
};