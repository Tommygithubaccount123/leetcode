class Solution {
public:
    //moores algo
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int majority = nums[0];
        for (int i=1;i<n;i++){
            if (nums[i]==majority){
                count += 1;
            } else {
                count -= 1;
            }
            if (count == 0){
                majority = nums[i];
                count = 1;
            }
        }
        return majority;
    }
};