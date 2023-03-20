class Solution {
private:
    int solve(int i, int n, vector<int> &price, vector<int> &length, vector<vector<int>> & dp) {

        if(n == 0) {
            return 0;
        }

        if(i == 0) {
            if(length[0] <= n) {
                return price[0] * n;
            }
            return 0;
        }

        if(dp[i][n] != -1) {
            return dp[i][n];
        }

        int notPick = solve(i-1, n, price, length, dp);
        int pick = INT_MIN;
        
        if(length[i] <= n) {
            pick = price[i] + solve(i, n - length[i], price, length, dp);
        }

        return dp[i][n] = max(pick, notPick);
    }
    
public:
    int cutRod(vector<int> &price, int n) {
        
        vector<int> length(n);
        
        for(int i = 0; i < n; i++) {
            length[i] = i+1;
        }

        // Approach 1: Memoization
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, length, dp);


        /*// Approach 2: Tabulation
        vector<vector<int>> dp(n, vector<int>(n+1, 0));

        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        for(int j = 0; j <= n; j++) {
            if(length[0] <= j) {
                dp[0][j] = price[0] * j;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= n; j++) {
                int notPick = dp[i-1][j];
                int pick = INT_MIN;
                if(length[i] <= j) {
                    pick = price[i] + dp[i][j - length[i]];
                }

                dp[i][j] = max(pick, notPick);
            }
        }
        return dp[n-1][n];
        */ 

        /*// Approach 3: Space optimization (using 2 array)
        vector<int> prev(n+1, 0);

        prev[0] = 0;

        for(int j = 0; j <= n; j++) {
            if(length[0] <= j) {
                prev[j] = price[0] * j;
            }
        }

        for(int i = 1; i < n; i++) {
            vector<int> temp(n+1, 0);
            temp[0] = 0;
            for(int j = 1; j <= n; j++) {
                int notPick = prev[j];
                int pick = INT_MIN;
                if(length[i] <= j) {
                    pick = price[i] + temp[j - length[i]];
                }

                temp[j] = max(pick, notPick);
            }
            prev = temp;
        }
        return prev[n];
        */

        /* //Approach 4: Space optimization (using 1 array)
        vector<int> prev(n+1, 0);

        prev[0] = 0;

        for(int j = 0; j <= n; j++) {
            if(length[0] <= j) {
                prev[j] = price[0] * j;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= n; j++) {
                int notPick = prev[j];
                int pick = INT_MIN;
                if(length[i] <= j) {
                    pick = price[i] + prev[j - length[i]];
                }

                prev[j] = max(pick, notPick);
            }
        }
        return prev[n];
        */
    }
};
