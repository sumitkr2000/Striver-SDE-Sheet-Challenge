class Solution {
private:
    int findPar(int u, vector<int> &parent) {
        
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findPar(parent[u], parent);
    }

    void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
        
        u = findPar(u, parent);
        v = findPar(v, parent);

        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[v] < rank[u]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool static comp(vector<int> &v1, vector<int> &v2) {
        return v1[2] < v2[2];
    }

public:
    int kruskalMST(int n, int m, vector<vector<int>> &graph) {

        sort(graph.begin(), graph.end(), comp);    
        vector<int> parent(n+1), rank(n+1, 0);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        int ans=  0;
        
        for(auto it: graph) {
            if(findPar(it[0], parent) != findPar(it[1], parent)) {
                ans += it[2];
                unionn(it[0], it[1], parent, rank);
            }
        }
        return ans;
    }
};
