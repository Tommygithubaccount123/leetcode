class Solution {
private:
    vector<vector<int>> result;
    vector<int> candidates;
    int target;
public:
    void dfs(int i, vector<int> curCombo, int total){
        if (total == this->target){
            result.push_back(curCombo);
            return;
        }
        if (i >= this->candidates.size() || total > this->target){
            return;
        }

        curCombo.push_back(this->candidates[i]);
        dfs(i, curCombo, total + candidates[i]);
        curCombo.pop_back();
        dfs(i+1, curCombo, total);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        this->candidates = candidates;
        this->target = target;
        dfs(0, {}, 0);
        return result;
        
    }
};