class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r){
            int mid = (r-l) / 2 + l;
            if (nums[mid] == target){return mid;}
            
            //left side
            if (nums[mid] >= nums[l]){
                if (target > nums[mid] || target < nums[l]){
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            //right side
            } else { 
                if (target < nums[mid] || target > nums[r]){
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};