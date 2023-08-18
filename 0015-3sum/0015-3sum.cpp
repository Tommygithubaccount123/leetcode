class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<n;i++){
            int a = nums[i];
            if (i>0 && nums[i-1] == a){
                continue;
            }
            a = nums[i];
            
            int l = i+1;
            int r = n-1;
            while (l < r){
                if (nums[l]+nums[r]+a > 0){
                    r--;
                } else if (nums[l]+nums[r]+a < 0) {
                    l++;
                }
                else{
                    result.push_back({a,nums[l],nums[r]});
                    l++;
                    while (l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return result;
    }
};