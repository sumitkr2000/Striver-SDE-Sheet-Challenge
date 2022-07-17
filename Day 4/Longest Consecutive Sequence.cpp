#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    if(n == 0) {
        return 0;
    }

    sort(arr.begin(), arr.end());
    vector<int> v;
    int cnt = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            continue;
        }

        if(arr[i] - arr[i-1] == 1) {
            cnt++;
        }
        else{
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    int ans = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        ans = max(ans,v[i]);
    }
    return ans;
}
