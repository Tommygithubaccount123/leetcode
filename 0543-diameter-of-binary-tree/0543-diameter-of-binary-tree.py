# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0
        
        depth, tree = self.do(root)
        return max(depth-1, tree)
    
    def do(self, node):
        if not node:
            return 0, 0
        
        left_depth, left_tree = self.do(node.left)
        right_depth, right_tree = self.do(node.right)

        depth = max(left_depth, right_depth) + 1
        tree = max(max(left_tree, right_tree), left_depth + right_depth)

        return depth, tree



        