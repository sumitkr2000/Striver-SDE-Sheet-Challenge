class Solution {
private:
    int lps(string temp) {

        int n = temp.size();
        vector<int> pi(n);
        pi[0] = 0;

        int i = 0, j = 1;

        while(j < n) {
            if(temp[i] == temp[j]) {
                pi[j] = i+1;
                i++;
                j++;
            }
            else {
                if(i == 0) {
                    pi[j] = 0;
                    j++;
                }
                else {
                    i = pi[i-1];
                }
            }
        }
        return pi[n-1];
    }

public:
    int solve(string A) {

        string B = A;
        reverse(B.begin(), B.end());

        string temp = A + "$" + B;

        return A.size() - lps(temp);
    }
};
