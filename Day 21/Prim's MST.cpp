#include<unordered_map>
#include<list>
#include<climits>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int,int>,int>> &g)
{
    unordered_map<int, list<pair<int,int>>> adjList;
    
    for(int i = 0; i < g.size(); i++) {

        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
    key[1] = 0;
    
    for(int i = 1; i < n; i++) {
        
        int mini = INT_MAX;
        int u;
        
        for(int v = 1; v <= n; v++) {
            if(mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];              
            }
        }
        
        mst[u] = true;
        
        for(auto it: adjList[u]) {
            int v = it.first;
            int w = it.second;
            
            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;      
    for(int i = 2; i <= n; i++) {

        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}
