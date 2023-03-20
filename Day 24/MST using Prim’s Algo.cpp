class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<bool> vis(V, 0);
        int ans = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            pair<int, int> p = pq.top();
            int node = p.second;
            int wt = p.first;
            pq.pop();
            
            if(!vis[node]) {
                vis[node] = 1;
                ans += wt;
                for(auto it: adj[node]) {
                    pq.push({it[1], it[0]});
                }
            }
        }
        return ans;
    }
};
