class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        int mid;
        int low = 0;
        int high = n;
        while (low != high){
            if (nums[low] < nums[high]){
                return nums[low];
            }
            
            mid = (high+low) / 2;
            if (nums[low] <= nums[mid]){
                low = mid+1;
            }
            else {
                high = mid;
            }   
        }
        return nums[low];
    }
};