class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<int>> storage;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j]==0){
                    vector<int> pair = {i,j};
                    storage.push(pair);
                } else {
                    mat[i][j] = -1; 
                }
            }
        }
        
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!storage.empty()){
            vector<int> queue_pair = storage.front();
            int row = queue_pair[0];
            int col = queue_pair[1];
            storage.pop();
            
            for (int i=0; i<4; i++){
                int new_row = row + dirs[i][0];
                int new_col = col + dirs[i][1];
                if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n || mat[new_row][new_col] != -1){continue;}
                mat[new_row][new_col] = mat[row][col] + 1;
                vector<int> new_pair = {new_row,new_col};
                storage.push(new_pair);
            }
        }
        
        return mat;
        
    }
};