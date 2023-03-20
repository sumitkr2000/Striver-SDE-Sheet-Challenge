class Solution {
private:	
    int solve(int i, int prev, int arr[], int n, vector<vector<int>> &dp) {
        
        if(i == n) {
            return 0;
        }
        
        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }
        
        int notTake = solve(i+1, prev, arr, n, dp);
        int take = INT_MIN;
	    
        if(prev == -1 || arr[i] > arr[prev]) {
            take = arr[i] + solve(i+1, i, arr, n, dp);
        }
        
        return dp[i][prev+1] = max(take, notTake);
    }	

public:
    int maxSumIS(int arr[], int n) {
		
	// Approach 1: Memoization
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return solve(0, -1, arr, n, dp);


	 /*// Approach 2: Tabulation
	 vector<int> dp(n);
	 int ans = arr[0];

	 for(int i = 0; i < n; i++) {
	     dp[i] = arr[i];
	 }

	 for(int i = 0; i < n; i++) {
	     for(int j = 0; j < i; j++) {
                 if(arr[j] < arr[i]) {
		     dp[i] = max(dp[i], arr[i]+dp[j]);
		 }
	      }
	      ans = max(ans, dp[i]);
	 }
	 return ans;
	 */
    }  
};
