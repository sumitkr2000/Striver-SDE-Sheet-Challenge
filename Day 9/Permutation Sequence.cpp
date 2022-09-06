class Solution {
private:
    void permutate(string &s) {
        
        int n = s.size();
        int i, j;
        
        for(i = n-2; i >= 0; i--) {
            if(s[i] < s[i+1]) {
                break;
            }
        }

        for(j = n-1; j > i; j--) {
            if(s[j] > s[i]) {
                break;
            }
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
    }
    
public:
    string getPermutation(int n, int k) {
        
        string s;
        for(int i = 1; i <= n; i++) {
            s += (i + '0');
        }
        
        while(k > 1) {
            permutate(s);
            k--;
        }
        return s;
    }
};
