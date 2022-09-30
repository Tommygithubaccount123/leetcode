class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        int n = nums.size();
        
        for (int numIndex=0; numIndex<n; numIndex++){
            int resultSize = result.size();
            for (int resIndex=0; resIndex<resultSize; resIndex++){
                vector<int> temp = result.at(resIndex);
                temp.push_back(nums.at(numIndex));
                result.push_back(temp);
            }
        }
        return result;
    }
};