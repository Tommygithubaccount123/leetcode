class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.m = len(grid)
        self.n = len(grid[0])
        result = 0
        self.visited = {}
        
        self.dirs = [(0,1), (0,-1), (1,0), (-1,0)]

        for i in range(self.m):
            for j in range(self.n):
                result += self.dfs(i, j, grid)
        return result

    def dfs(self, x, y, grid):
        if x < 0 or y < 0 or x >= self.m or y >= self.n:
            return 0
        if (x,y) in self.visited:
            return 0
        if grid[x][y] == "0" or grid[x][y] == "2":
            return 0

        self.visited[(x,y)] = True
        for dx,dy in self.dirs:
            self.dfs(x+dx,y+dy, grid)
        return 1
        