# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return None
        self.do(root)
        return root
    
    def do(self, node):
        if not node:
            return
        
        left = node.left
        tmp = left
        right = node.right
        self.do(left)
        self.do(right)
        node.left = right
        node.right = tmp
        return