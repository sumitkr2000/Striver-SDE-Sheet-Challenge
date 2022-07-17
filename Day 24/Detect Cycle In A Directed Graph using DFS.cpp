#include<unordered_map>
#include<list>
#include<queue>
bool directedGrpahCycle(int node, unordered_map<int, list<int>> &adjList,
 unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
    
    visited[node] = 1;
    dfsVisited[node] = 1;
    
    for(auto i: adjList[node]) {
        if(!visited[i]) {
            bool checkForward = directedGrpahCycle(i, adjList, visited, dfsVisited);
            if(checkForward == true) {
                return true;
            }
        }
        else if(visited[i] == true && dfsVisited[i] == true){
            return true;
        }
    }
    
    dfsVisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {
  
    unordered_map<int, list<int>> adjList;
    
    for(int i = 0; i < edges.size(); i++) {
        
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
    
    /*Method 1: Using DFS
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool ans = directedGrpahCycle(i, adjList, visited, dfsVisited);
            if(ans == true) {
                return true;
            }
        }
    }  
    return false;
    */
    
    //Method 2: Uisng BFS
    unordered_map<int, int> indegree;
    
    for(auto i: adjList) {       
        for(auto j: i.second) {
            indegree[j]++;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int cnt = 0;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        cnt++;
        
        for(auto i: adjList[front]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    if(cnt == n) {
        return false;
    }
    return true;
}
