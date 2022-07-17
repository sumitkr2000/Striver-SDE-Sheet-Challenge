void dfs(int node,  unordered_map<int, list<int>> &adjList, vector<vector<int>> &ans, unordered_map<int, bool> &visited, vector<int> &component) {
    
    component.push_back(node);
    visited[node] = 1;
    
    for(auto i: adjList[node]) {
        if(!visited[i]) {
            dfs(i, adjList, ans, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;   
    for(int i = 0; i < E; i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, adjList, ans, visited, component);
            ans.push_back(component);
        }
    }   
    return ans; 
}
