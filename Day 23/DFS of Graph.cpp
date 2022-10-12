class Solution {
  private:
    void dfs(int node, vector<int> adj[], unordered_map<int, bool> &vis, vector<int> &ans) {
        
        vis[node] = true;
        ans.push_back(node);
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }
  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        unordered_map<int, bool> vis;
        dfs(0, adj, vis, ans);
        return ans;
    }
};
