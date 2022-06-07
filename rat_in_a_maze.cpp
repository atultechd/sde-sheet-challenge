void solve(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &res, vector<vector<int>> &ans){
        if(x<0 || y<0 || x>=n || y>=n || maze[x][y]==0 || ans[x][y]==1)return;
        if(x==n-1 && y==n-1 && maze[x][y] == 1){
            vector<int>path;
            ans[x][y] = 1;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    path.push_back(ans[i][j]);
                }
            }
            res.push_back(path);
        }    
        ans[x][y] = 1;
       
            solve(x+1,y,maze,n,res,ans);
    
            solve(x,y-1,maze,n,res,ans);
        
            solve(x,y+1,maze,n,res,ans);
        
            solve(x-1,y,maze,n,res,ans);
    
        ans[x][y] = 0;
    }
        

    vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
       vector<vector<int>> res;
       vector<vector<int>> ans(n,vector<int>(n,0));
//        if(maze[0][0] == 0) return ans;
       solve(0,0,maze,n,res,ans);
       return res;
    }