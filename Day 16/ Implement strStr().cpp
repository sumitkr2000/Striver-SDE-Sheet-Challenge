class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.length();
        int k = needle.length();
        
        if(k == 0) return 0;
        if(k > n) return -1;
        
        for(int i = 0; i < n-k+1; i++) {
            string s = "";
            for(int j = i; j < i+k; j++) {
                s.push_back(haystack[j]);
            }
            if(s == needle) {
                return i;
                break;
            }
        }
        return -1;
    }
};
