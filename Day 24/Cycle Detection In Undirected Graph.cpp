#include<queue>
#include<unordered_map>
#include<list>
bool bfsCycleDetection(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited) {
    
    unordered_map<int, int> parent;
    
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(auto it: adjList[front]) {
            if(visited[it] == true && it != parent[front]) {
                return true;
            }            
            else if(visited[it] != true){
                q.push(it);
                visited[it] = true;
                parent[it] = front; 
            }
        }
    }
    return false;
}

bool dfsCycleDetection(int node, int parent, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited) {
    
    visited[node] = true;
    
    for(auto it: adjList[node]) {
        if(visited[it] != true) {
            bool checkForward = dfsCycleDetection(it, node, adjList, visited);
            
            if(checkForward) {
                return true;
            }            
        }
        else if(it != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
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
            bool ans = dfsCycleDetection(i, -1, adjList, visited);
            if(ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}
