class Solution {
private:
    vector<vector<int>> result;
public:
    void dfs(int i, vector<int> curCombo, int total, vector<int>& candidates, int target){
        if (total == target){
            result.push_back(curCombo);
            return;
        }
        if (i >= candidates.size() || total > target){
            return;
        }

        curCombo.push_back(candidates[i]);
        dfs(i, curCombo, total + candidates[i], candidates, target);
        curCombo.pop_back();
        dfs(i+1, curCombo, total, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        dfs(0, {}, 0, candidates, target);
        return result;
        
    }
};