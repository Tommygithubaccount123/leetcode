class Solution {
private:
    vector<vector<int>> result;
public:
    void dfs(int i, vector<int> curCombo, int total, int target, vector<int>& candidates){
        if (total == target){
            result.push_back(curCombo);
            return;
        }
        if (i >= candidates.size() || total > target){
            return;
        }

        curCombo.push_back(candidates[i]);
        dfs(i, curCombo, total + candidates[i], target, candidates);
        curCombo.pop_back();
        dfs(i+1, curCombo, total, target, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        // vector<int> combo = {};
        dfs(0, {}, 0, target, candidates);
        return result;
        
    }
};