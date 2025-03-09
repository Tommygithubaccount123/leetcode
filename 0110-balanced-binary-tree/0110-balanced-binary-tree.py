# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.storage = dict()

    def depth(self, root):
        if not root:
            self.storage[root] = 0
            return 0
        math = max(self.depth(root.left), self.depth(root.right)) + 1
        self.storage[root] = math
        return math

    def work(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        left = self.storage[root.left]
        right = self.storage[root.right]
        if abs(left-right) > 1:
            return False
        return self.work(root.right) and self.work(root.left)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.depth(root)
        return self.work(root)