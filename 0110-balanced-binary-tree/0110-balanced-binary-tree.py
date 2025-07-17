# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.result = True
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        self.do(root)
        return self.result

    def do(self, node):
        if not node:
            return 0
        
        left = self.do(node.left)
        right = self.do(node.right)

        if abs(left - right) > 1:
            self.result = False
        return max(left, right) + 1



