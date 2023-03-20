class Solution {
private:
    void solve(int i, int j, vector<vector<int>> &image, int startColor, int color) {
        
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || 
           image[i][j] != startColor) {
            return;
        }
        
        image[i][j] = color;
        
        solve(i+1, j, image, startColor, color);
        solve(i-1, j, image, startColor, color);
        solve(i, j+1, image, startColor, color);
        solve(i, j-1, image, startColor, color);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int startColor = image[sr][sc];
        
        if(startColor == color) {
            return image;
        }
        
        solve(sr, sc, image, startColor, color);        
        return image;
    }
};
