// DP Problem

class Solution {
private:
    int solve(int i, int V, int coins[], vector<vector<int>> &dp) {
      
        if(i == 0) {
            if(V%coins[i] == 0) {
                return V/coins[i];
            } 
            return 1e9;
        }
        
        if(dp[i][V] != -1) {
            return dp[i][V];
        }
        
        int notTake = solve(i-1, V, coins, dp);
        int take = INT_MAX;
        if(coins[i] <= V) {
            take = 1 + solve(i, V-coins[i], coins, dp);
        }
        
        return dp[i][V] = min(take, notTake);
    }

public:
	int minCoins(int coins[], int M, int V) {
    
        //Approach 1: Memoization
        vector<vector<int>> dp(M, vector<int>(V+1, -1));
        int ans = solve(M-1, V, coins, dp);
        
        return ans == 1e9 ? -1 : ans;
        
        /*//Approach 2: Tabulation
        vector<vector<int>> dp(n, vector<int>(V+1, 1e9));
        
        for(int i = 0; i <= V; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= V; j++) {
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(take, notTake);
            }
        }
        return dp[n-1][V] == 1e9 ? -1 : dp[n-1][V];
        */
        
        /*//Approach 3: Space optimized
        vector<int> prev(V+1, 1e9), curr(V+1, 1e9);
        
        for(int i = 0; i <= V; i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= V; j++) {
                int notTake = prev[j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + curr[j-coins[i]];
                }

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }
        return prev[V] == 1e9 ? -1 : prev[V];
        */
	  } 
};
