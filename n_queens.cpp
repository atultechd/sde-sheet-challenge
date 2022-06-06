

bool is_safe(int row, int col, vector<vector<int>>&board, int n){
    int x=row;
    int y=col;
    while(y >= 0){
        if(board[x][y]==1) return false;
        y--;
    }
    
    x=row;
    y=col;
    while(x>= 0 && y>=0){
        if(board[x][y]==1) return false;
        x--;
        y--;
    }
    
    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1) return false;
        x++;
        y--;
    }
}

void add_sol(vector<vector<int>>&ans, vector<vector<int>>&board, int n){
    vector<int>temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int n, vector<vector<int>> &board, vector<vector<int>> &ans, int col){
   if(col == n){
       add_sol(ans,board,n);
       return;
   }
   for(int row=0; row<n; row++){
       if(is_safe(row,col,board,n)){
           board[row][col] = 1;
           solve(n,board,ans,col+1);
           board[row][col] = 0;
       }
   }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    solve(n,board,ans,0);
    return ans;
}