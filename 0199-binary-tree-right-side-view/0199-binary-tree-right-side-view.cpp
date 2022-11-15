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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(res, 0, root);
        return res;
    }
    
    void helper(vector<int>& res, int level, TreeNode* root){
        if (!root){return;}
        if (res.size() == level){
            res.push_back(root->val);
        }
        helper(res, level+1, root->right);
        helper(res, level+1, root->left);
    }
};