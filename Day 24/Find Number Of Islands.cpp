void dfs(int i, int j, int** arr, int n, int m) {        
    //base case
    if(i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 0) {
        return;
    }

    arr[i][j] = 0;

    dfs(i-1, j, arr, n, m);
    dfs(i+1, j, arr, n, m);
    dfs(i, j-1, arr, n, m);
    dfs(i, j+1, arr, n, m);
    dfs(i-1, j-1, arr, n, m);
    dfs(i+1, j-1, arr, n, m);
    dfs(i-1, j+1, arr, n, m);
    dfs(i+1, j+1, arr, n, m);   
}

int getTotalIslands(int** arr, int n, int m)
{
    int islandCnt = 0;    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                islandCnt++;
                dfs(i, j, arr, n, m);
            }
        }
    }        
    return islandCnt;
}
