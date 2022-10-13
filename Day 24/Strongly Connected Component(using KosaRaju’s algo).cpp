#include<bits/stdc++.h>
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
    
   vis[node] = 1;    
   for(auto it: adj[node]) {
       if(!vis[it]) {
           dfs(it, vis, adj, st);
       }
   }
   st.push(node);
}

void solve(int node, vector<int> &vis, vector<vector<int>> &trans, vector<int> &res) {
    
   vis[node] = 1;
   res.push_back(node);    
   for(auto it: trans[node]) {
       if(!vis[it]) {
           solve(it, vis, trans, res);
       }
   }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{ 
    vector<vector<int>> adj(n, vector<int>()); 
    for(auto it: edges) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(n, 0);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    
    vector<vector<int>> trans(n, vector<int>());
    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        for(auto it: adj[i]) {
            trans[it].push_back(i);
        }
    }
    
    vector<vector<int>> ans;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            vector<int> res;
            solve(node, vis, trans, res);
            ans.push_back(res);
        }
    }
    return ans;
}
