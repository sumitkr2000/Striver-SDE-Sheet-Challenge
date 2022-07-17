#include<bits/stdc++.h>
bool isPalindrome(string &str, int i, int j) {

    while(i <= j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string &str, int i, int j, vector<vector<int>> &dp) {

    if((i >= j) || isPalindrome(str, i, j)) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k = i; k < j; k++) {

        //int tempAns = 1 + solve(str, i, k, dp) + solve(str, k+1, j, dp);

        //optimised memoization
        int left;
        if(dp[i][k] != -1) {
            left = dp[i][k];
        }
        else{
            left = solve(str, i, k, dp);
        }

        int right;
        if(dp[k+1][j] != -1) {
            right = dp[k+1][j];
        }
        else{
            right = solve(str, k+1, j, dp);
        }

        int tempAns = 1 + left + right;

        ans = min(ans, tempAns);
    }

    return dp[i][j] = ans;
}

int palindromePartitioning(string str) {
    
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return solve(str, 0, n-1, dp);
}
