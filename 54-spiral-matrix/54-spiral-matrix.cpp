class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        int direction = 1;
        
        while (left <= right && top <= bottom){
            if (direction == 1){
                for (int i=left; i<=right; i++){
                    result.push_back(matrix[top][i]);
                }
                top += 1;
                direction = 2;
            }
            else if (direction == 2){
                for (int i=top; i<=bottom; i++){
                    result.push_back(matrix[i][right]);
                }
                right -= 1;
                direction = 3;
            }
            else if (direction == 3){
                for (int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom -= 1;
                direction = 4;
            }
            else if (direction == 4){
                for (int i=bottom; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left += 1;
                direction = 1;
            }
        }
        return result;
    }
};