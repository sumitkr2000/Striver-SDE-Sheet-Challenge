#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
void topoSort(int node, unordered_map<int, list<int>> &adjList,
             vector<bool> &visited, stack<int> &sorted) {
    
    visited[node] = true;
    
    for(auto i: adjList[node]) {
        if(!visited[i]) {
            topoSort(i, adjList, visited, sorted);
        }
    }   
    sorted.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int, list<int>> adjList;
    
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    /*Method 1: Using DFS
    vector<bool> visited(v);
    stack<int> sorted;
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            topoSort(i, adjList, visited, sorted);
        }
    }
    
    vector<int> ans;
    while(!sorted.empty()) {
        ans.push_back(sorted.top());
        sorted.pop();
    }   
    return ans;
    */
    
    //Method 2: Using BFS
    vector<int> indegree(v);
    
    for(auto i: adjList) {       
        for(auto j: i.second) {
            indegree[j]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> ans;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto i: adjList[front]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}
