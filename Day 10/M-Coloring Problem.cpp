class Solution{
private:
    bool isPossible(int node, int col, vector<int> &arr, unordered_map<int, list<int>> &adjList) {
        
        for(auto it: adjList[node]) {
            if(arr[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int m, int n, vector<int> &arr, unordered_map<int, list<int>> &adjList) {
        //base case
        if(node == n) {
            return true;
        }
        
        for(int col = 1; col <= m; col++) {
            
            if(isPossible(node, col, arr, adjList)) {
                arr[node] = col;
                if(solve(node+1, m, n, arr, adjList) == true) {
                    return true;
                }
                arr[node] = 0;
            }
        }
        return false;
    }
    
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        unordered_map<int, list<int>> adjList;
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
               if(graph[i][j] == 1) {
                   adjList[i].push_back(j);
                   adjList[j].push_back(i);
               }
           }
        }
        
        vector<int> arr(n, 0);
        return solve(0, m, n, arr, adjList);
    }
};
