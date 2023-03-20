class Solution {
private:
    bool solve(int i, string &A, unordered_map<string, bool> &mp, vector<int> &dp) {
        
        if(i == A.size()) {
            return true;
        }
        
        if(dp[i] != -1) {
            return dp[i];
        }
        
        for(int k = i; k < A.size(); k++) {
            if(mp.find(A.substr(i, k-i+1)) != mp.end()) {
                if(solve(k+1, A, mp, dp)) {
                    return dp[i] = true;
                }
            }
        }
        
        return dp[i] = false;
    }
    
public:
    int wordBreak(string A, vector<string> &B) {
        
        unordered_map<string, bool> mp;
        
        for(auto it: B) {
            mp[it] = true;
        }
        
        vector<int> dp(A.size(), -1);
        return solve(0, A, mp, dp);
    }
};
