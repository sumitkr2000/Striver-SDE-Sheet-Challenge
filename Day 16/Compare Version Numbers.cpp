class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        
        while(i < n || j < m) {
            int rev1 = 0, rev2 = 0;
            
            while(i < n && version1[i] != '.') {
                rev1 = rev1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < m && version2[j] != '.') {
                rev2 = rev2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if(rev1 > rev2) {
                return 1;
            }
            if(rev2 > rev1) {
                return -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
