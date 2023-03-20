class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        
        if(i >= grid.size() || j >= grid[0].size()) {
            return 1e9;
        }
        
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int down = grid[i][j] + solve(i+1, j, grid, dp);
        int right = grid[i][j] + solve(i, j+1, grid, dp);
        
        return dp[i][j] = min(down ,right);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        //Approach 1: Memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));        
        return solve(0, 0, grid, dp);
    
        
        /*// Approach 2: Tabulation
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j>= 0; j--) {
                if(i == n-1 && j == m-1) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int down = 1e9;
                    if(i < n-1) {
                        down = grid[i][j] + dp[i+1][j];
                    }
                    
                    int right = 1e9;
                    if(j < m-1) {
                        right = grid[i][j] + dp[i][j+1];
                    }
                    
                    dp[i][j] = min(down ,right);
                }
            }
        }
        return dp[0][0];
        */
        
        /*// Approach 3: Space optimized
        vector<int> next(m, 0), curr(m, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j>= 0; j--) {
                if(i == n-1 && j == m-1) {
                    curr[j] = grid[i][j];
                }
                else {
                    int down = 1e9;
                    if(i < n-1) {
                        down = grid[i][j] + next[j];
                    }
                    
                    int right = 1e9;
                    if(j < m-1) {
                        right = grid[i][j] + curr[j+1];
                    }
                    
                    curr[j] = min(down ,right);
                }
            }
            next = curr;
        }
        return next[0];
        */
    }
};
