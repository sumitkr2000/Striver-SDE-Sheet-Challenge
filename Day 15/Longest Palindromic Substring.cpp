class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, 0));

        string ans = s[0];
        int maxLen = 1;
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                ans = s.substr(i, 2);
                maxLen = 2;
            }
        }

        for(int i = n-3; i >= 0; i--) {
            for(int j = i+2; j < n; j++) {
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    if(j - i + 1 > maxLen) {
                        ans = s.substr(i, j-i+1);
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};
