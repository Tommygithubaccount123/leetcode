class Solution:
    def __init__(self):
        self.dirs = [(1,0), (-1,0), (0, 1), (0, -1)]
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans += self.helper(i, j, grid)
        return ans

    def helper(self, i, j, grid):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
            return 0
        spot = grid[i][j]
        if spot != "1":
            return 0
        grid[i][j] = "2"
        for direction in self.dirs:
            self.helper(i + direction[0], j + direction[1], grid)
        return 1
        

