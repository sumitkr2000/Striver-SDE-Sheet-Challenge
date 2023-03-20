class Solution {
public:
  int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {

      vector<vector<int>> adjList(n+1);
    
      for(auto &it: edges) {
          adjList[it[0]].push_back(it[1]);
      }
    
      vector<int> indegree(n+1, 0);
    
      for(auto it: adjList) {       
          for(auto node: it.second) {
              indegree[node]++;
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

          for(auto it: adjList[front]) {
              indegree[it]--;
              if(indegree[it] == 0) {
                  q.push(it);
              }
          }
      }
      
      return cnt != n;
  }
};
