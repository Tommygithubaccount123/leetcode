class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        if (i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0||grid[i][j]==2){return 0;}
        grid[i][j] = 2;
        int curIsland = 1;
        for (auto dir : dirs){
            curIsland += dfs(grid, i+dir.first, j+dir.second);
        }
        return curIsland;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int biggest = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){  
                    biggest = max(biggest, dfs(grid, i, j));
                }
            }
        }
        return biggest;
    }
};