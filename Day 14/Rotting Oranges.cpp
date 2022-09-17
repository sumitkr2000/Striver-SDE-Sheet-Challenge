class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {   
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0; 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        int ans = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<int,int> p = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int r = p.first + dir[j];
                    int c = p.second + dir[j+1];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
            if(!q.empty()) {
                ans++; 
            }
        }
        
        if(fresh != 0) return -1;
        return ans;
    }
};
