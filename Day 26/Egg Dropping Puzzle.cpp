class Solution
{
    private:
    int solve(int n, int k, vector<vector<int>> &dp) {
        
        if(k == 0 || k == 1 || n == 1) {
            return k;
        }
        
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        
        int mini = INT_MAX;
        for(int i = 1; i <= k; i++) {
            int temp = 1 + max(solve(n-1, i-1, dp), solve(n, k-i, dp));
            mini = min(mini, temp);
        }
        
        return dp[n][k] = mini;
    }
    
    public:
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};
