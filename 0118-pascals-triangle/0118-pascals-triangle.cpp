class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1){return {{1}};}
        if (numRows == 2){return {{1},{1,1}};}
        // if (numRows == 3){return {{1},{1,1},{1,2,1}};}
        vector<vector<int>> ans = {{1},{1,1},{1,2,1}};
        for (int i=2; i<numRows-1; i++){
            vector<int> newRow = {1};
            for (int j=0; j<ans[i].size()-1; j++){
                newRow.push_back(ans[i][j] + ans[i][j+1]);
            }
            newRow.push_back(1);
            ans.push_back(newRow);
        }
        
        return ans;
    }
};