class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = 9;
        int n = 9;
        map<pair<int,int>, unordered_set<char>> squares;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        for (int row=0; row<m; row++){
            for (int col=0; col<n; col++){
                if (board[row][col] == '.'){continue;}
                if (rows[row].find(board[row][col]) != rows[row].end()){
                    return false;
                }
                if (cols[col].find(board[row][col]) != cols[col].end()){
                    return false;
                }
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
            
                int bigRow = row / 3;
                int bigCol = col / 3;
                pair<int, int> key = {bigRow, bigCol};
                if (squares[key].find(board[row][col]) != squares[key].end()){
                    return false;
                }
                squares[key].insert(board[row][col]);
            }
        }
        
        return true;
    }
};