class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> mp;
        mp[A[0]] = 0;
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            A[i] += A[i-1];
            
            if(A[i] == 0) {
                ans = i+1;
            }
            
            if(mp.find(A[i]) != mp.end()) {
                ans = max(ans, i - mp[A[i]]);
            }
            else {
                mp[A[i]] = i;
            }
        }
        return ans;
    }
};
