class Solution {
private:
    bool isPalindrome(int i, int j, string &s) {
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int i, string &s, vector<string> &op, vector<vector<string>> &ans) {
        //base case
        if(i == s.size()) {
            ans.push_back(op);
            return;
        }
        
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                op.push_back(s.substr(i, j-i+1));
                solve(j + 1, s, op, ans);
                op.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> op;
        
        solve(0, s, op, ans);
        return ans;
    }
};
