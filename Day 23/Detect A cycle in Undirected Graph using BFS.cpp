class Solution {
private:
    bool bfsCycleDetection(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited) {

        unordered_map<int, int> parent;
        queue<int> q;
        
        q.push(node);
        visited[node] = 1;
        parent[node] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto it: adjList[front]) {
                if(visited[it] && it != parent[front]) {
                    return true;
                }            
                else if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                    parent[it] = front; 
                }
            }
        }
        return false;
    }
    
public:
    bool cycleDetection (vector<vector<int>>& edges, int n, int m) {
        
        unordered_map<int, list<int>> adjList;
        
        for(int i = 0; i < m; i++) {        
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                if(bfsCycleDetection(i, adjList, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
