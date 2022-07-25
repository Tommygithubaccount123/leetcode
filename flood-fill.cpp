class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        flooder(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    
    
    
    void flooder(vector<vector<int>>& image, int r, int c, int color, int oldcolor){
        if (r < 0 || c < 0){return;}
        if (r >= image.size() || c >= image[0].size()){return;}
        if (image[r][c]!=oldcolor || image[r][c]==color){return;}
        image[r][c] = color;
        flooder(image,r+1,c,color,oldcolor);
        flooder(image,r-1,c,color,oldcolor);
        flooder(image,r,c-1,color,oldcolor);
        flooder(image,r,c+1,color,oldcolor);
    }
};