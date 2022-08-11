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
    bool isValidBST(TreeNode* root) {
        return recursiveHelper(root, NULL, NULL);
    }
    
    bool recursiveHelper(TreeNode* root, TreeNode* small, TreeNode* big){
        if (!root){return true;}
        if (small && root->val <= small->val || big && root->val >= big->val){
            return false;
        }
        return recursiveHelper(root->left, small, root) && recursiveHelper(root->right, root, big);
    }
};