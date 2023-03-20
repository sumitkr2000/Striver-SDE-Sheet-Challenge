class Solution {
private:
    bool dfsCycleDetection(int node, int parent, vector<vector<int>> &adjList, vector<bool> &vis) {

        vis[node] = true;

        for(auto it: adjList[node]) {
            if(!vis[it]) {
                if(dfsCycleDetection(it, node, adjList, vis)) {
                    return true;
                }            
            }
            else if(it != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool cycleDetection (vector<vector<int>>& edges, int n, int m) {

        vector<vector<<int>> adjList(n+1);
        
        for(auto &it: edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                if(dfsCycleDetection(i, -1, adjList, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
