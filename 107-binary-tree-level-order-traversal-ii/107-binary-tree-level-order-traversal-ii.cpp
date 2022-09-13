/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root){return result;}
        queue<TreeNode*> storage;
        storage.push(root);
        stack<vector<int>> reverse;
        while(!storage.empty()){
            int len = storage.size();
            vector<int> level;
            for (int i=0; i<len; i++){
                TreeNode* top = storage.front();
                storage.pop();
                level.push_back(top->val);
                if (top->left){
                    storage.push(top->left);
                }
                if (top->right){
                    storage.push(top->right);
                }
            }
            reverse.push(level);
        }
        
        while(!reverse.empty()){
            result.push_back(reverse.top());
            reverse.pop();
        }
        return result;
    }
};