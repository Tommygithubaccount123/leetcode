class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        
        isZig = False
        levels = []
        q = deque()
        q.append(root)
        while q:
            level = []
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            if isZig:
                level.reverse()
            
            levels.append(level)
            isZig = not isZig

        return levels