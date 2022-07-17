class Solution
{
    private:
    int solve(int n, int k, vector<vector<int>> &dp) {
        //base cond.
        if(n == 1 || k == 0 || k == 1) {
            return k;
        }
        
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        
        int ans = INT_MAX;
                
        for(int i = 1; i <= k; i++) {
            
            int low;
            if(dp[n-1][i-1] != -1) {
                low = dp[n-1][i-1];
            }
            else {
                low = solve(n-1, i-1, dp);
                dp[n-1][i-1] = low;
            }
            
            int high;
            if(dp[n][k-i] != -1) {
                high = dp[n][k-i];
            }
            else {
                high = solve(n, k-i, dp);
                dp[n][k-i] = high;
            }
            
            int tempAns = 1 + max(low, high);
            
            ans = min(ans, tempAns);
        }
        return dp[n][k] = ans;
    }
    
    public:
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int> (k+1 ,-1));
        return solve(n, k, dp);
    }
};
