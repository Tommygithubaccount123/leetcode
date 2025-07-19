# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        self.count = 0
        return self.inOrder(root, k)
    
    def inOrder(self, node, k):
        if not node:
            return None
        
        left = self.inOrder(node.left, k)
        self.count += 1
        if self.count == k:
            return node.val
        right = self.inOrder(node.right, k)
        return left if (left is not None) else right
