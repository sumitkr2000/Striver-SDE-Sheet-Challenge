bool isSafe(int board[9][9], int row, int col, int val) {
    
    for(int i = 0; i < 9; i++) {      
        if(board[row][i] == val)
            return false;
            
        if(board[i][col] == val)
            return false;
        
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(int board[9][9]) {
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            
            if(board[i][j] == 0) {
                for(int val = 1; val <= 9; val++) {
                    if(isSafe(board, i, j, val)) {
                        board[i][j] = val;                        
                        bool checkForward = solve(board);
                        
                        if(checkForward) 
                            return true;
                        else{
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }  
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    
    solve(matrix);
}
