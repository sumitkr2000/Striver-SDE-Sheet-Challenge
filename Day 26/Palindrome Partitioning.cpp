class Solution{
private:
    bool isPalindrome(int i, int j, string &str) {
        
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string &str, vector<int> &dp) {
        
        if(i >= str.size()) {
            return 0;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        int mini = INT_MAX;
        for(int k = i; k < str.size(); k++) {
            if(isPalindrome(i, k, str)) {
                int cuts = 1 + solve(k+1, str, dp);
                mini = min(mini, cuts);
            }
        }
        return dp[i] = mini;
    }

public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n, -1);
        return solve(0, str, dp)-1;
    }
};
