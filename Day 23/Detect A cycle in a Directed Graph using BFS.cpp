#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {
  
    unordered_map<int, list<int>> adjList;    
    for(int i = 0; i < edges.size(); i++) {        
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
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
