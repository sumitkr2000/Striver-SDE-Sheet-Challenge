#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    
	pair<int,int> ans;
    unordered_map<int, pair<int, bool>> mp;
    
    for(int i = 0; i < n; i++) {
        mp[arr[i]].first++;
        mp[arr[i]].second = true;
    }
    
    for(int i = 1; i <= n; i++) {
        if(mp[i].second == 0) {
            ans.first = i;
        }
        if(mp[i].first > 1) {
            ans.second = i;
        }
    } 
    return ans;
}
