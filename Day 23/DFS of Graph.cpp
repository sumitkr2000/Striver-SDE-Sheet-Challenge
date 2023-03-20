class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
        
        vis[node] = true;
        ans.push_back(node);
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }
  
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<bool> vis(V, 0);
        dfs(0, adj, vis, ans);
        return ans;
    }
};
