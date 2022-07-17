#include<bits/stdc++.h>
void solve(vector<int> v, vector<int> &output, vector<vector<int>> &ans) {
    //base case
    if(v.size() == 0) {
        if(output.size() != 0) {
            ans.push_back(output);
        }
        return;
    }

    vector<int> op1 = output;
    vector<int> op2 = output;

    op2.push_back(v[0]);
    v.erase(v.begin() + 0);

    solve(v, op1, ans);
    solve(v, op2, ans);

    return;
}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> output;

    solve(v, output, ans);

    sort(ans.begin(), ans.end());
    return ans;
}
