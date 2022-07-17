long countWaysToMakeChange(int *denominations, int n, int value)
{
    long dp[n+1][value+1];
        
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < value+1; j++) {

            if(i == 0) {
                dp[i][j] = 0;
            }
            if(j == 0) {
                dp[i][j] = 1;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < value+1; j++) {

            if(denominations[i-1] <= j) {
                dp[i][j] = dp[i][j-denominations[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][value];
}
