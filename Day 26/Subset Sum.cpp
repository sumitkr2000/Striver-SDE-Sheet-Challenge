bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
    //base case
    if(k == 0) {
        return true;
    }
    
    if(i == 0) {
        return arr[0] == k;
    }
        
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    
    bool notTake = solve(i-1, k, arr, dp);
    bool take = false;
    if(k >= arr[i]) {
        take = solve(i-1, k-arr[i], arr, dp);
    }
    
    return dp[i][k] = notTake | take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
  
    //Approach 1: Memoization
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return solve(n-1, k, arr, dp);
    
    
    /* //Approach 2: Tablulation
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    dp[0][arr[0]] = 1;
    
    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
       
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool notTake = dp[i-1][j];
            bool take = false;
            if(j >= arr[i]) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTake | take;
        }
    }
    return dp[n-1][k];
    */
    
    /*//Approach 3: Space optimisation
    vector<bool> prev(k+1, 0);
    prev[arr[0]] = 1;

    for(int i = 1; i < n; i++) {
        vector<bool> temp(k+1, 0);
        prev[0] = 1;
        for(int j = 1; j <= k; j++) {
            bool notTake = prev[j];
            bool take = false;
            if(j >= arr[i]) {
                take = prev[j-arr[i]];
            }
            temp[j] = notTake | take;
        }
        prev = temp;
    }
    return prev[k];
    */
}
