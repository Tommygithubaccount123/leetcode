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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        
        if(root){que.push(root);}
        
        while(!que.empty()){
            int len = que.size();
            vector<int> sub;
            for (int i=0; i<len; i++){
                TreeNode* top = que.front();
                sub.push_back(top->val);
                if (top->left){
                    que.push(top->left);
                }
                if (top->right){
                    que.push(top->right);
                }
                que.pop();
            }
            ans.push_back(sub);
        }
        
        return ans;
    }
};