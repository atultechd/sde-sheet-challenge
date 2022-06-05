bool is_safe(int row, int col, int matrix[9][9], int val){
    for(int i=0; i<9; i++){
        if(matrix[row][i] == val) return false;
        if(matrix[i][col] == val) return false;
        if(matrix[3*(row/3)+ i/3][3*(col/3)+ i%3] == val) 
            return false;
    }
    return true;
}

bool solve(int matrix[9][9]){
    int n = 9;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(matrix[row][col] == 0){
                for(int val = 1; val<= 9; val++){
                    if(is_safe(row, col, matrix, val)){
                        matrix[row][col] = val;
                        bool solve_further = solve(matrix);
                        if(solve_further) return true;
                        else matrix[row][col] = 0; 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return solve(matrix);
}
