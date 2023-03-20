class Solution{
private:
    bool isSafe(int i, int j, int n, vector<vector<int>> &m) {

        if(i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1) {
            return true;
        }
        return false;
    }

    void solve(int i, int j, int n, vector<vector<int>> &m, string &path, vector<string> &ans) {
        
        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }

        m[i][j] = 0;

        //down
        if(isSafe(i+1, j, n, m)) {
            path.push_back('D');
            solve(i+1, j, n, m, path, ans);
            path.pop_back();
        }
        
        //left
        if(isSafe(i, j-1, n, m)) {
            path.push_back('L');
            solve(i, j-1, n, m, path, ans);
            path.pop_back();
        }
        
        //right
        if(isSafe(i, j+1, n, m)) {
            path.push_back('R');
            solve(i, j+1, n, m, path, ans);
            path.pop_back();
        }

        //up
        if(isSafe(i-1, j, n, m)) {
            path.push_back('U');
            solve(i-1, j, n, m, path, ans);
            path.pop_back();
        }

        m[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        string path = "";
        
        if(m[0][0] == 1) {
           solve(0, 0, n, m, path, ans);
        }
        
        return ans;
    }
};
