class Solution {
private:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &set) {
        
        for(auto it: graph[node]) {
            if(set[it] == -1) {
                set[it] = set[node] == 0 ? 1 : 0;
                if(!dfs(it, graph, set)) {
                    return false;
                }
            }
            else if(set[it] == set[node]) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> set(n, -1);
        for(int i = 0; i < n; i++) {
            if(set[i] == -1) {
                set[i] = 0;
                if(!dfs(i, graph, set)) {
                    return false;
                }
            }
        }
        return true;
    }
};
