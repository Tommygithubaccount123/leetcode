# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.result = []
        self.levels = dict()

    def rightSideView(self, root):
        if not root:
            return []
        self.do(root, 0)
        return self.result
        
    def do(self, node, level):
        if not node:
            return
        
        if level not in self.levels:
            self.levels[level] = True
            self.result.append(node.val)

        self.do(node.right, level+1)
        self.do(node.left, level+1)
        return
        
