#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    int cnt = 0;
    int xorr = 0;
    
    for(auto it: arr) {
        xorr = xorr^it;
        if(xorr == x) {
            cnt++;
        }
        
        if(mp.find(xorr^x) != mp.end()) {
            cnt += mp[xorr^x];
        }
        mp[xorr]++;
    }
    return cnt;
}
