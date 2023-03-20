class Solution{
private:
    bool isPossible(int node, int col, vector<int> &color, vector<vector<int>> &g) {
        
        for(auto it: g[node]) {
            if(color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int m, int n, vector<int> &color, vector<vector<int>> &g) {
  
        if(node == n) {
            return true;
        }
        
        for(int col = 1; col <= m; col++) {
            if(isPossible(node, col, color, g)) {
                color[node] = col;
                if(solve(node+1, m, n, color, g)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    
public:

    bool graphColoring(bool graph[101][101], int m, int n) {
        
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
               if(graph[i][j] == 1) {
                   g[i].push_back(j);
                   g[j].push_back(i);
               }
           }
        }
        
        vector<int> color(n, 0);
        return solve(0, m, n, color, g);
    }
};
