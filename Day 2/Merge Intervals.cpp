/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
#include <bits/stdc++.h> 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    vector<int> temp;
    int maxi = INT_MIN;

    if(n == 1) {
        return intervals;
    }

    for(int i = 0; i < n-1; i++) {

        maxi = max(maxi, intervals[i][1]);

        if(temp.empty()) {
            temp.push_back(intervals[i][0]);
        }

        if(i == n-2 && maxi >= intervals[i+1][0]) {
            temp.push_back(max(intervals[i+1][1],maxi));
            ans.push_back(temp);
        }

        if(maxi < intervals[i+1][0]) {
            temp.push_back(maxi);
            ans.push_back(temp);
            maxi = INT_MIN;
            temp.clear();
        }

        if(i == n-2 && maxi < intervals[i+1][0]) {
            ans.push_back(intervals[n-1]);
        }
    }

    if(temp.size() == 1) {
        temp.push_back(maxi);
        ans.push_back(temp);
    }

    return ans;
}

