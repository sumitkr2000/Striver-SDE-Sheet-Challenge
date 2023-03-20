class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp) {

        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = solve(i-1, j, dp);
        int left = solve(i, j-1, dp);

        return dp[i][j] = up + left;
    }
    
public:
    int uniquePaths(int m, int n) {
        
        //Appraoch 1: Memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
        
        /*//Approach 2: Tabulation
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) {
                        up = dp[i-1][j];
                    }
                    if(j > 0) {
                        left = dp[i][j-1];
                    }               
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
        */

        /*//Approach 3: Space Optimized
        vector<int> prev(n);

        for(int i = 0; i < m; i++) {
            vector<int> temp(n);

            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                }
                else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) {
                        up = prev[j];
                    }
                    if(j > 0) {
                        left = temp[j-1];
                    }               
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
        */
        
        /*//Approach 4: Combination
        int N = m + n - 2;
        int r = min(n, m) - 1;
        
        double res = 1;
        for(int i = 1; i <= r; i++) {
            res *= (N - r + i)/i;
        }
        return (int)res;
        */
    }
};
