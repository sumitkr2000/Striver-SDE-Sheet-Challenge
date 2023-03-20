class Solution {
private:
    bool bfsCycleDetection(int node, vector<vector<int>> &adjList, vector<bool> &vis) {
        
        vector<int> par(vis.size());
        queue<int> q;
        
        q.push(node);
        vis[node] = 1;
        par[node] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto it: adjList[front]) {
                if(vis[it] && it != par[front]) {
                    return true;
                }            
                else if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                    par[it] = front; 
                }
            }
        }
        return false;
    }
    
public:
    bool cycleDetection (vector<vector<int>>& edges, int n, int m) {
        
        vector<vector<int>> adjList(n+1);
        
        for(auto &it: edges) {
            adjList[it[0]].push_back(it[1);
            adjList[it[1].push_back(it[0]);
        }

        vector<bool> vis(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                if(bfsCycleDetection(i, adjList, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
