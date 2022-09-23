class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size(), m = needle.size();
        vector<int> lps(m);
        
        lps[0] = 0;
        int i = 0, j = 1;
        
        while(j < m) {
            if(needle[i] == needle[j]) {
                lps[j] = i+1;
                i++;
                j++;
            }
            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                }
                else {
                    i = lps[i-1];
                }
            }
        }
        
        i = 0, j = 0;
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                if(j == 0) {
                    i++;
                }
                else {
                    j = lps[j-1];
                }
            }
        }
        
        if(j == m) {
            return i - j;
        }
        return -1;
    }
};
