# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.storage = {}
    def rob(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if root in self.storage:
            return self.storage[root]
        
        case1 = 0
        if root.left:
            case1 += self.rob(root.left)
        if root.right:
            case1 += self.rob(root.right)

        case2 = root.val
        if root.left:
            case2 += self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            case2 += self.rob(root.right.left) + self.rob(root.right.right)

        value = max(case1, case2)
        self.storage[root] = value
        return value
        
