# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []

        result = []
        queue = [root]
        while queue:
            n = len(queue)
            sub_list = []
            for i in range(n):
                node = queue.pop(0)
                if node:
                    sub_list.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if sub_list:
                result.append(sub_list)
        return result



        

        
        