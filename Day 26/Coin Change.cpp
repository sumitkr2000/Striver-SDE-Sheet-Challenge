class Solution {
private:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
      
        if(i == 0) {
            if(amount%coins[i] == 0) {
                return amount/coins[i];
            } 
            return 1e9;
        }
        
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        
        int notTake = solve(i-1, amount, coins, dp);
        int take = INT_MAX;
        if(coins[i] <= amount) {
            take = 1 + solve(i, amount-coins[i], coins, dp);
        }
        
        return dp[i][amount] = min(take, notTake);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        //Approach 1: Memoization
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        
        return ans == 1e9 ? -1 : ans;
        
        
        /*//Approach 2: Tabulation
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        
        for(int i = 0; i <= amount; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(take, notTake);
            }
        }
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
        */
        
        /*//Approach 3: Space optimized
        vector<int> prev(amount+1, 1e9), curr(amount+1, 1e9);
        
        for(int i = 0; i <= amount; i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = INT_MAX;
                if(coins[i] <= j) {
                    take = 1 + curr[j-coins[i]];
                }

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }
        return prev[amount] == 1e9 ? -1 : prev[amount];
        */
    }
};
