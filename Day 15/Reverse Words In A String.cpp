class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        int i = 0;
        string ans;
        
        while(i < n) {
            while(i < n && s[i] == ' ') {
                i++;
            }
            if(i >= n) {
                break;
            }
            
            int j = i+1;
            while(j < n && s[j] != ' ') {
                j++;
            }
            
            string temp = s.substr(i, j-i);
            ans.empty() ? ans = temp : ans = temp + " " + ans;
            
            i = j+1;
        }
        return ans;
    }
};
