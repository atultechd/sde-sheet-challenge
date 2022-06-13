#include <bits/stdc++.h>

// int solve(int m, int n){
//     if(m==0 && n==0) return 1;
//     if(m<0 || n<0) return 0;
//     int right = solve(m-1, n);
//     int down = solve(m, n-1);
//     return right+down;
// }

// int uniquePaths(int m, int n){
//   return solve(m-1,n-1);
// }



// Using nCr method
int uniquePaths(int m, int n){
    int N = n+m-2;
    int r = m-1;
    double res = 1;
    for(int i=1; i<=r; i++){
        res = res * (N - r + i)/i;
    }
    return (int)res;
}