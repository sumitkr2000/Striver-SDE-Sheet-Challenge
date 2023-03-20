class Solution {
private:
    void solve(int i, string &s, unordered_map<string, bool> &mp, vector<string> &op, vector<string> &ans) {

        if(i == s.size()) {
            string res = "";
            for(auto it: op) {
                res += it;
                res += ' ';
            }
            res.pop_back();
            ans.push_back(res);
            return;
        }

        for(int j = i; j < s.size(); j++) {
            string word = s.substr(i, j-i+1);
            if(mp[word] == true) {
                op.push_back(word);
                solve(j + 1, s, mp, op, ans);
                op.pop_back();
            }
        }
    }
    
public:
    vector<string> wordBreak(string &s, vector<string> &dictionary) {
        
        unordered_map<string, bool> mp;
        for(auto it: dictionary) {
            mp[it] = true;
        }

        vector<string> ans, op;

        solve(0, s, mp, op, ans);
        return ans;
    }
};
