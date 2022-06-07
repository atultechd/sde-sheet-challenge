

void check_for_all_directions(int **arr, int n, int m, int i, int j){
    if(i>=0 && i<n && j>=0 && j<m && arr[i][j] == 1){
        arr[i][j] = 0;
        check_for_all_directions(arr,n,m,i,j+1);
        check_for_all_directions(arr,n,m,i+1,j+1);
        check_for_all_directions(arr,n,m,i+1,j);
        check_for_all_directions(arr,n,m,i+1,j-1);
        check_for_all_directions(arr,n,m,i,j-1);
        check_for_all_directions(arr,n,m,i-1,j-1);
        check_for_all_directions(arr,n,m,i-1,j);
        check_for_all_directions(arr,n,m,i-1,j+1);
    }
}

int getTotalIslands(int** arr, int n, int m){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                count++;
                check_for_all_directions(arr,n,m,i,j);
            }
        }
    }
    return count;
}
