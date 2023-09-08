class Solution {
public:
    vector<string> result;
    
    void helper(int n, int close, int open, string current){
        if (current.size() == n*2){
            result.push_back(current);
            return;
        }
        
        if (open < n){
            helper(n, close, open+1, current+"(");
        }
        if (close < open){
            helper(n, close+1, open, current+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        helper(n, 0, 0, "");
        return result;
    }
};