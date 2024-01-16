class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(int i, int j, vector<vector<char>>& grid){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]=='0' || grid[i][j]=='2'){
            return 0;
        }
        
        grid[i][j] = '2';
        for (auto dir : dirs){
            dfs(i+dir.first, j+dir.second, grid);
        }
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == '1'){
                    result += dfs(i,j,grid);                
                }
            }
        }
        return result;
    }
};