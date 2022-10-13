int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> edgeWt(V, INT_MAX);
        vector<bool> isMst(V, 0);
        edgeWt[0] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            isMst[node] = 1;
            
            for(auto it: adj[node]) {
                int v = it[0];
                int w = it[1];
                
                if(!isMst[v] && w < edgeWt[v]) {
                    edgeWt[v] = w;
                    pq.push({w, v});
                }
            }
        }
        
        int ans = 0;
        for(auto it: edgeWt) {
            ans += it;
        }
        
        return ans;
    }
};
