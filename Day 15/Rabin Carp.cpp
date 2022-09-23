class Solution {
private:
    int mod = 5381;
    bool isSubstr(string str, string pat) {

        int n = str.size();
        int m = pat.size();
        int hp = 1;
        int j = 0;
        vector<int> ans;

        for(int i = 0; i < m; i++) {
            hp = (hp*26)%mod;
        }

        int hash1 = 0;
        int hash2 = 0;
        for(int i = 0; i < m; i++) {
            hash1 = (hash1*26 + pat[i])%mod;
            hash2 = (hash2*26 + str[i])%mod;
        }

        
        for(int i = 0; i <= n-m; i++) {
            if(hash1 == hash2) {
                for(j = 0; j < m; j++) {
                    if(str[i+j] != pat[j]) {
                        break;
                    }
                }
                if(j == m) {
                    return 1;
                }
            }

            if(i < n-m) {
                hash2 = (26*(hash2 - str[i]*hp) + str[i+m])%mod;
                if(hash2 < 0) {
                    hash2 += 5381;
                }
            }
        }
        return 0;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        
        int n = a.size(), m = b.size();
        
        int ans = 0;
        string temp;
        
        while(temp.size() < b.size()) {
            temp += a;
            ans++;
        }
        
        if(isSubstr(temp, b)) {
            return ans;
        }
        if(isSubstr(temp+a, b)) {
            return ans+1;
        }
        
        return -1;
    }
};
