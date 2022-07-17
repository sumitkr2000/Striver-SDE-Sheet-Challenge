class Solution{
    private:

    bool isSafe(vector<vector<int>> &m, int n, vector<vector<bool>> &visited, int x, int y) {

        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1)) {
            return true;
        }
        else {
            return false;
        }
    }

    void solve(vector<vector<int>> &m, int n, vector<vector<bool>> &visited, string path, int x, int y, vector<string> &ans) {

        //base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        //down
        if(isSafe(m, n, visited, x+1, y)) {
            path.push_back('D');
            solve(m, n, visited, path, x+1, y, ans);
            path.pop_back();
        }
        
        //left
        if(isSafe(m, n, visited, x, y-1)) {
            path.push_back('L');
            solve(m, n, visited, path, x, y-1, ans);
            path.pop_back();
        }
        
        //right
        if(isSafe(m, n, visited, x, y+1)) {
            path.push_back('R');
            solve(m, n, visited, path, x, y+1, ans);
            path.pop_back();
        }

        //up
        if(isSafe(m, n, visited, x-1, y)) {
            path.push_back('U');
            solve(m, n, visited, path, x-1, y, ans);
            path.pop_back();
        }

        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
       vector<string> ans;
       string path = "";
       vector<vector<bool>> visited(n, vector<bool> (n, 0));

       if(m[0][0] == 0) {
           return ans;
       }

       solve(m, n, visited, path, 0, 0, ans);
       return ans;
    }
};
