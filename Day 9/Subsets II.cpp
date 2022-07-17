#include<bits/stdc++.h>
void solve(vector<int> &arr, int i, vector<int> &output, vector<vector<int>> &res) {
        //base case
        if(i == arr.size()) {
            sort(output.begin(), output.end());
            res.push_back(output);
            return;
        }
        
        vector<int> op1 = output;
        vector<int> op2 = output;
        
        op2.push_back(arr[i]);
        
        solve(arr, i+1, op1, res);
        solve(arr, i+1, op2, res);
        
        return;
    }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> res;
    vector<int> output;
    int i = 0;
    solve(arr, i, output, res);

    set<vector<int>> st;        
    for(int i = 0; i < res.size(); i++) {
        st.insert(res[i]);
    }

    vector<vector<int>> ans;

    set<vector<int>>:: iterator it;
    for(it = st.begin(); it != st.end(); it++){
        vector<int> temp = *it;
        ans.push_back(temp);
    }        
    return ans;
}
