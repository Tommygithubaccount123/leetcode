# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        queue = [root]
        result = []
        left_to_right = 1
        while (queue):
            n = len(queue)
            level = []
            for i in range(n):
                node = queue.pop(0)
                if node:
                    level.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if level:
                if left_to_right:
                    result.append(level)
                else:
                    result.append(level[::-1])
            left_to_right = not left_to_right
        return result

