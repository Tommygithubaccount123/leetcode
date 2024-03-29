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
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    
    void helper(TreeNode* root){
        if (!root){return;}
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                
                if (cur->left){
                    q.push(cur->left);
                }
                if (cur->right){
                    q.push(cur->right);
                }
                TreeNode* tmp = cur->right;
                cur->right = cur->left;
                cur->left = tmp;
            }
        }
        return;
        
    }
};