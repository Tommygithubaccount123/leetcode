class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        
        count = 0
        for i in range(self.n):
            for j in range(self.m):
                count += self.check(grid, i, j)
        
        return count
    
    def check(self, grid, i, j):
        if i >= self.n or i < 0:
            return 0
        if j >= self.m or j < 0:
            return 0
        
        
        val = grid[i][j]
        if val in "02":
            return 0
        grid[i][j] = "2"
        
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]    
        for dir in dirs:
            self.check(grid, i+dir[0], j+dir[1])
        
        return 1