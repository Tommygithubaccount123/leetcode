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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root){return ans;}
        
        queue<TreeNode*> storage;
        storage.push(root);
        bool zig = 0;
        while(!storage.empty()){
            vector<int> level;
            int len = storage.size();
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
            if (zig){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            zig = !zig;
        }
        return ans;
    }
};