# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        return self.helper(root, float('-inf'), float('inf'))
    
    def helper(self, root, small, big):
        if not root:
            return True
        if root.val >= big or root.val <= small:
            return False
        return self.helper(root.left, small, root.val) and self.helper(root.right, root.val, big)