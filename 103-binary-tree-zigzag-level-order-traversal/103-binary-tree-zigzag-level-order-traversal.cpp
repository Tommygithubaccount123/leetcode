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
            int len = storage.size();
            vector<int> level(len);
            for (int i=0; i<len; i++){
                TreeNode* top = storage.front();
                storage.pop();
                if (zig){
                    level[len-1-i] = top->val;
                } else {
                    level[i] = top->val;
                }
                if (top->left){
                    storage.push(top->left);
                }
                if (top->right){
                    storage.push(top->right);
                }
            }
            ans.push_back(level);
            zig = !zig;
        }
        return ans;
    }
};