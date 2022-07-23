/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){return nullptr;}
        if (root->left == p && root->right == q){return root;}
        if (root->left == q && root->right == p){return root;}
        
        if (findRoot(root->left,p) && root == q){return root;}
        if (findRoot(root->left,q) && root == p){return root;}
        if (findRoot(root->right,p) && root == q){return root;}
        if (findRoot(root->right,q) && root == p){return root;}
        
        if (findRoot(root->right,p) && findRoot(root->left,q)){return root;}
        if (findRoot(root->right,q) && findRoot(root->left,p)){return root;}
        
        TreeNode* result = lowestCommonAncestor(root->left,p,q);
        if (result){
            return result;
        }
        return lowestCommonAncestor(root->right,p,q);
    }
    TreeNode* findRoot(TreeNode* root, TreeNode* target){
            if (!root){return nullptr;}
            if (root==target){return target;}
            TreeNode* result = findRoot(root->left,target);
            if (result){
                return result;
            }
            return findRoot(root->right,target);
        }
};