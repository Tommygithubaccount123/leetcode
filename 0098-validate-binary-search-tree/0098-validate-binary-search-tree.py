# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        return self.do(root, float("-inf"), float("inf"))
    
    def do(self, node, small, big):
        if not node:
            return True
        if node.val > small and node.val < big:
            left = self.do(node.left, small, node.val)
            right = self.do(node.right, node.val, big)
            return left and right
        return False
        