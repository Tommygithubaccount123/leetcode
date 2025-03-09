# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self, root):
        if not root:
            return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        left = self.depth(root.left)
        right = self.depth(root.right)
        if abs(left-right) > 1:
            return False
        return self.isBalanced(root.right) and self.isBalanced(root.left)