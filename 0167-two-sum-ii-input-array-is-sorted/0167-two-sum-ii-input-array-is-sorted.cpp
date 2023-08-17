class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int right = n-1;
        int left = 0;
        
        int cur = numbers[left] + numbers[right];
        while (cur != target){
            cur = numbers[left] + numbers[right];
            if (cur > target){
                right--;
            } else if (cur < target){
                left++;
            }
        }
        
        return {left+1,right+1};
    }
};