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
        int result = 0;
        calc(root,result);
        return result;
    }
    
    int calc(TreeNode* root, int &res){
        if (!root){return 0;}
        int left = calc(root->left,res);
        int right = calc(root->right,res);
        res = max(res,left+right);
        return max(left,right)+1;
    }
    
};