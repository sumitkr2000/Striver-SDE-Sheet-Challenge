class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> set(n, -1);
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(set[i] == -1) {                
                q.push(i);
                set[i] = 0;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(auto it: graph[node]) {
                        if(set[it] == -1) {
                            set[it] = set[node] == 0 ? 1 : 0;
                            q.push(it);
                        }
                        else if(set[it] == set[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
