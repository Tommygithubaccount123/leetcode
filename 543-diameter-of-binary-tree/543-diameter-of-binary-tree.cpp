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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root){return 0;}
        int length = height(root->left) + height(root->right);
        int left_length = diameterOfBinaryTree(root->left);
        int right_length = diameterOfBinaryTree(root->right);
        return max(length,max(left_length,right_length));
        
        
    }
    
    int height(TreeNode* root){
        if (!root){return 0;}
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left,right);
    }
};