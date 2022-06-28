class Solution {
private:
    bool isSafe(vector<vector<char>> &board, int row, int col, int val) {
    
    for(int i = 0; i < 9; i++) {      
        if(board[row][i] == val+'0')
            return false;
            
        if(board[i][col] == val+'0')
            return false;
        
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val+'0')
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board) {
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            
            if(board[i][j] == '.') {
                for(int val = 1; val <= 9; val++) {
                    if(isSafe(board, i, j, val)) {
                        board[i][j] = val + '0';                        
                        bool checkForward = solve(board);
                        
                        if(checkForward) 
                            return true;
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }  
    return true;
}
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};
