class Solution {
private:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        
        if(i < 0) {
            return j + 1;
        }
        if(j < 0) {
            return i + 1;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(word1[i] == word2[j]) {
            return solve(i-1, j-1, word1, word2, dp);
        }
            
        int insert = 1 + solve(i, j-1, word1, word2, dp);
        int deletee = 1 + solve(i-1, j, word1, word2, dp);
        int replace = 1 + solve(i-1, j-1, word1, word2, dp);
        
        return dp[i][j] = min(insert, min(deletee, replace));
    }
    
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size(), m = word2.size();
        
        // Approach 1: Memoization
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2, dp);
        
        
        /* //Approach 2: Tabulation
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int insert = 1 + dp[i][j-1];
                    int deletee = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert, min(deletee, replace));
                }
            }
        }
        return dp[n][m];
        */
        
        /* //Approach 3: Space optimized
        vector<int> prev(m+1, 0);
        
        for(int j = 0; j <= m; j++) {
            prev[j] = j;
        }
        
        for(int i = 1; i <= n; i++) {
            vector<int> curr(m+1);
            curr[0] = prev[0]+1;
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    int insert = 1 + curr[j-1];
                    int deletee = 1 + prev[j];
                    int replace = 1 + prev[j-1];

                    curr[j] = min(insert, min(deletee, replace));
                }
            }
            prev = curr;
        }
        return prev[m];
        */
    }
};
