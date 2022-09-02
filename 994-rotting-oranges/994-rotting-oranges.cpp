class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> storage;
        int fresh = 0;
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    fresh += 1;
                }
                else if (grid[i][j] == 2){
                    storage.push({i, j});
                }
            }
        }
        
        int time = 0;
        while (!storage.empty() && fresh > 0){
            int size = storage.size();
            while (size){
                vector<int> cur = storage.front();
                storage.pop();
                for (auto dir : dirs){
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x < 0 || x >= grid.size()){continue;}
                    if (y < 0 || y >= grid[0].size()){continue;}
                    if (grid[x][y] == 1){
                        grid[x][y] = 2;
                        storage.push({x,y});
                        fresh -= 1;
                    }
                }
                size -= 1;
            }
            time += 1;
        }
        return fresh == 0 ? time : -1;
    }   
};