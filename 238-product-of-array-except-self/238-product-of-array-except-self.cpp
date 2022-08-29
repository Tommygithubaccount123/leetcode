class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int forward = 1;
        int backward = 1;
        for (int i=0; i<n; i++){
            result[i] *= forward;
            forward *= nums[i];
        }
        
        for (int i=n-1; i>=0; i--){
            result[i] *= backward;
            backward *= nums[i];
        }
        
        return result;
    }
};