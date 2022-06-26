#include<set>
#include<unordered_map>
#include<list>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int, list<pair<int,int>>> adjList;
    
    for(int i = 0; i < edges; i++) {
        
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    set<pair<int,int>> s;
    vector<int> dist(vertices);
    
    for(int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    
    dist[source] = 0;    
    s.insert(make_pair(0, source));
    
    while(!s.empty()) {
        auto top = *(s.begin());
        
        int nodeDist = top.first;
        int node = top.second;
        
        s.erase(s.begin());
        
        for(auto it: adjList[node]) {
            if(nodeDist + it.second < dist[it.first]) {
                auto record = s.find(make_pair(dist[it.first], it.first));
                
                if(record != s.end()) {
                    s.erase(record);
                }
                
                dist[it.first] = nodeDist + it.second;
                s.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
    return dist;
}
