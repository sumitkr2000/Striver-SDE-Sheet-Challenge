int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        
    if(i >= j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k = i; k < j; k++) {

        int tempAns = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];

        mini = min(mini, tempAns);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        
    return solve(arr, 1, N-1, dp);
}
