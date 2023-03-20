class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        
        int x = row, y = col;
        
        //check for left columns in same row
        while(y >= 0) {
            if(board[x][y] == 'Q') return false;
            y--;
        }
        
        //check for upper diagonal
        y = col;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        
        //check for lower diagonal
        x = row, y = col;
        while(x < n && y >= 0) {
            if(board[x][y] == 'Q') return false;
            x++;
            y--;
        }
        return true;
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
        
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        
        solve(0, ans, board, n);
        return ans;
    }
};
