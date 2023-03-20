class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        pq.push({0, S});
        ans[S] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]) {
                int currNode = it[0];
                int currDist = it[1];
                
                if(dist + currDist < ans[currNode]) {
                    ans[currNode] = dist + currDist;
                    pq.push({dist+currDist, currNode});
                }
            }
        }
        return ans;
    }
};
