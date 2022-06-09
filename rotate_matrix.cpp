void rotateMatrix(vector<vector<int>> &mat, int n, int m){
  int a =0,b=n-1,c=0,d=m-1;
    if(b==0 or d ==0)return ;
    while(c<d and a<b) {
        int temp = mat[a][a];
        for(int j = c+1;j<=d;j++){
            swap(temp,mat[a][j]); 
        }
        for(int i=a+1;i<=b;i++){
            swap(temp,mat[i][d]);
        }
        for(int j= d-1;j>=c;j--){
            swap(temp,mat[b][j]);
        }
        for(int i = b-1;i>=a;i--){
            swap(temp,mat[i][c]);
        }

        a++;b--;
        c++;d--;
    }
}