#include<bits/stdc++.h>
//Approach 1: Memoization
int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    //base case
    if(i == 0 && j == 0) {
        return grid[0][0];
    }

    if(i < 0 || j < 0) {
        return 1e9;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = grid[i][j] + solve(grid, i-1, j, dp);
    int left = grid[i][j] + solve(grid, i, j-1, dp);

    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    
    /* //Approach 1: Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(grid, n-1, m-1, dp);
    */
    
    /* //Approach 2: Tabulation
    vector<vector<int>> dp(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }
            else {
                int up = 1e9;
                int left = 1e9;
                if(i > 0) {
                    up = grid[i][j] + dp[i-1][j];
                }
                if(j > 0) {
                    left = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(up, left);
            }
         }
    }
    return dp[n-1][m-1];
    */
    
    //Approach 3: Space optimisation
    vector<int> prev(m, 0);
    
    for(int i = 0; i < n; i++) {
        vector<int> temp(m, 0);
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                temp[j] = grid[i][j];
            }
            else{
                int up = 1e9;
                int left = 1e9;
                
                if(i > 0) {
                    up = grid[i][j] + prev[j];
                }
                if(j > 0) {
                    left = grid[i][j] + temp[j-1];
                }
                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    return prev[m-1];
}
