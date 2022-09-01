class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]=='1'){
                    tracker(grid, i, j);
                    islands += 1;
                }
            }
        }
        return islands;
    }
    
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}}; //R, L, UP, DOWN
    void tracker(vector<vector<char>>& grid, int x, int y){
        if (x < 0 || x >= grid.size()){return;}
        if (y < 0 || y >= grid[0].size()){return;}
        if (grid[x][y]=='0' || grid[x][y]=='2'){return;}
        
        grid[x][y] = '2';
        for (auto dir : dirs){
            tracker(grid, x+dir[0], y+dir[1]);
        }
    }
};