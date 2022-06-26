int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    
    //running the loop n-1 times as per the bellman ford's algorithm
    for(int i = 1; i < n; i++) {       
        for(int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    //to check negative cycle
    bool flag = 0;
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])) {
            flag = 1;
        }
    }   
    return dist[dest];
}
