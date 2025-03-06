# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode], storage=dict()) -> int:
        if (root is None):
            return 0
        if (root in storage):
            return storage[root]

        children = self.rob(root.right) + self.rob(root.left)
        grand = 0
        if (root.right is not None):
            grand += self.rob(root.right.right) + self.rob(root.right.left)
        if (root.left is not None):
            grand += self.rob(root.left.right) + self.rob(root.left.left)
        value = max(children, root.val + grand)
        storage[root] = value
        return value


        