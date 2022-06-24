#include<bits/stdc++.h>

// TC - O(log(min(n,m))), SC -O(1)
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(n<m)return ninjaAndLadoos(row2,row1,n,m,k);
    int low = max(0,k-n);
    int high = min(k,m);
    while(low<=high){
        int p1 = (low+high) >> 1;
        int p2 = k-p1;
        
        int l1 = p1==0 ? INT_MIN : row1[p1-1];
        int l2 = p2==0 ? INT_MIN : row2[p2-1];
        int r1 = p1==m ? INT_MAX : row1[p1];
        int r2 = p2==n ? INT_MAX : row2[p2];
        
        if(l1<=r2 && l2<=r1)return max(l1,l2);
        else if(l1 > r2) high = p1-1;
        else low = p1+1;
    }
    return 1;
}