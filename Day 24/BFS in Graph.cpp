#include<unordered_map>
#include<queue>
#include<set>
void createAdjList(vector<pair<int,int>> &edges, unordered_map<int, set<int>> &adjList) {
    
    for(int i = 0; i < edges.size(); i++) {
        
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(int node, unordered_map<int, set<int>> &adjList, vector<int> &ans, unordered_map<int, bool> &visited) {
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto i: adjList[front]) {
            if(visited[i] != 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    createAdjList(edges, adjList);
    
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            bfs(i, adjList, ans, visited);
        }
    }   
    return ans; 
}
