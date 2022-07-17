void solve(vector<vector<int>>& image, int n, int m, int i, int j, int temp, int newColor) {        
    //base case
    if(i < 0 || i >=n || j < 0 || j >=m || image[i][j] == newColor || image[i][j] != temp) {
        return;
    }

    image[i][j] = newColor;

    //recursive call
    solve(image, n, m, i-1, j, temp, newColor);
    solve(image, n, m, i+1, j, temp, newColor);
    solve(image, n, m, i, j-1, temp, newColor);
    solve(image, n, m, i, j+1, temp, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    int temp = image[x][y];

    solve(image, n, m, x, y, temp, newColor);
    return image;
}
