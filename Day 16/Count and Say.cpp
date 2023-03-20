class Solution {
public:
    string countAndSay(int n) {
        
        string ans = "1";
        
        for(int i = 2; i <= n; i++) {
            string temp;
            int cnt = 1;
            for(int j = 0; j < ans.size(); j++) {
                if(j == ans.size()-1 || ans[j] != ans[j+1]) {
                    temp += to_string(cnt);
                    temp += ans[j];
                    cnt = 0;
                }
                cnt++;
            }
            ans = temp;
        }
        return ans;
    }
};
