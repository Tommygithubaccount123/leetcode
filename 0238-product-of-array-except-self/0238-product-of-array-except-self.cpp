class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> postfix(n,1);
        prefix[0] = nums[0];
        postfix[n-1] = nums[n-1];
        
        for (int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i];
        }
        
        for (int i=n-2; i>=0; i--){
            postfix[i] = postfix[i+1] * nums[i];
        }
        
        for (int i=0; i<n; i++){
            int pre = 1;
            int post = 1;
            if (i > 0){
                pre = prefix[i-1]; 
            }
            if (i < n-1){
                post = postfix[i+1];
            }
            nums[i] = pre * post;
        }
        return nums;
    }
};