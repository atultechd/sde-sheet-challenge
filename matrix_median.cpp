#include<bits/stdc++.h>

// brute force
int getMedian(vector<vector<int>> &matrix)
{
    vector<int>res;
    int ans;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            res.push_back(matrix[i][j]);
        }
    }
    sort(res.begin(), res.end());
    return res[res.size()/2];
}

//............................................................

// optimal approach
int count_smaller(vector<int> &mat, int num){
    int start = 0, end = mat.size()-1;
    while(start <= end){
        int mid = (start+end)>>1;
        if(mat[mid] <= num) start = mid+1;
        else end = mid-1;
    }
    return start;
}
int getMedian(vector<vector<int>> &matrix){
    int low = 1, high = 1e6;
    int n = matrix.size();
    int m = matrix[0].size();
    while(low <= high){
        int mid = (low+high)>>1;
        int count = 0;
        for(int i=0; i<n; i++){
            count += count_smaller(matrix[i], mid);
        }
        if(count <= (n*m) >> 1)low = mid+1;
        else high = mid-1;
    }
    return low;
}