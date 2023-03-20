class Solution {
private:
    bool directedGrpahCycle(int node, vector<vector<int>> &adjList, vector<bool> &vis, vector<bool> &dfsVis) {

        vis[node] = dfsVis[node] = 1;

        for(auto it: adjList[node]) {
            if(!vis[it]) {
                if(directedGrpahCycle(it, adjList, vis, dfsVis)) {
                    return true;
                }
            }
            else if(dfsVis[it]) {
                return true;
            }
        }

        dfsVis[node] = 0;
        return false;
    }

public:
    int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {

        vector<vector<int>> adjList(n);
     
        for(int i = 0; i < edges.size(); i++) {
            adjList[it[0]].push_back(it[1]);
        }

        vector<bool> vis(n, 0), dfsVis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(directedGrpahCycle(i, adjList, vis, dfsVis)) {
                    return true;
                }
            }
        }  
        return false;
    }
};
