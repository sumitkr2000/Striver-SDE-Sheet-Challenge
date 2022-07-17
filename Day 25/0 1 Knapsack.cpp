int topTobottom(int w, vector<int> &weights, vector<int> &values, int n) {
        
    int dp[n+1][w+1];

    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < w+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < w+1; j++) {
            if(weights[i-1] <= j) {
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            } 
        }
    }
    return dp[n][w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return topTobottom(w, weights, values, n);
}
