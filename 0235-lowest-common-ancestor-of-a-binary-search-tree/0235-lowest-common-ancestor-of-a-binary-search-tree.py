# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        x, y, found = self.do(root, p, q)
        return found

    def do(self, node, p, q, found=None):
        if not node:
            return False, False, None
        if found:
            return True, True, found

        q_found = p_found = False
        if node.val == p.val:
            p_found = True
        if node.val == q.val:
            q_found = True

        l_p, l_q, found_l = self.do(node.left, p, q)
        r_p, r_q, found_r = self.do(node.right, p, q)

        if found_l:
            return True, True, found_l
        if found_r:
            return True, True, found_r
        if p_found and (l_q or r_q):
            return True, True, node
        if q_found and (l_p or r_p):
            return True, True, node
        if (l_p and r_q) or (l_q and r_p):
            return True, True, node
        
        return p_found or (l_p or r_p), q_found or (l_q or r_q), None


        

        