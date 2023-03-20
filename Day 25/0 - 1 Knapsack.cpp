class Solution {
private:
    int solve(int i, int W, int n, int wt[], int val[], vector<vector<int>> &dp) {
        
        if(i == n) {
            return 0;
        }
        
        if(dp[i][W] != -1) {
            return dp[i][W];
        }
        
        int notTake = solve(i+1, W, n, wt, val, dp);
        int take = INT_MIN;
        
        if(wt[i] <= W) {
            take = val[i] + solve(i+1, W-wt[i], n, wt, val, dp);
        }
        
        return dp[i][W] = max(take, notTake);
    }
    
public:
    int knapSack(int W, int wt[], int val[], int n) {
        
        // Approach 1: Memoization
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(0, W, n, wt, val, dp);
        
        
        /*// Approach 2: Tabulation
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = W; j >= 0; j--) {
                int notTake = dp[i+1][j];
                int take = INT_MIN;
                
                if(wt[i] <= j) {
                    take = val[i] + dp[i+1][j-wt[i]];
                }
                
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[0][W];
        */
        
        /*// Approach 3: Space optimized
        vector<int> next(W+1, 0), curr(W+1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = W; j >= 0; j--) {
                int notTake = next[j];
                int take = INT_MIN;
                
                if(wt[i] <= j) {
                    take = val[i] + next[j-wt[i]];
                }
                
                curr[j] = max(take, notTake);
            }
            next = curr;
        }
        return curr[W];
        */
    }
};
