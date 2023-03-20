class Solution {
private:
    void topoDFS(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
        
        vis[node] = 1;
        
	for(auto it: adj[node]) {
	    if(!vis[it]) {
		topoDFS(it, adj, vis, st);
	    }
	}
	st.push(node);
    }
    
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
            
	vector<bool> vis(V, 0);
	stack<int> st;
	vector<int> ans;

	for(int i = 0; i < V; i++) {
	    if(!vis[i]) {
	    	topoDFS(i, adj, vis, st);
	    }
	 }

	 while(!st.empty()) {
	    ans.push_back(st.top());
	    st.pop();
	 }
	 return ans;
    }
};
