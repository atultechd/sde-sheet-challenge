#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){

    typedef pair<int,pair<int,int>> pii;

    vector<int> res;

    priority_queue<pii,vector<pii>,greater<pii>> minh;

    for(int row=0; row<k; row++){
        int col = 0;
        int val = kArrays[row][col];
        int r=row, c=col;
        
        minh.push(make_pair(val, make_pair(r,c)));
    }

    while(minh.size() > 0){
        pair<int, pair<int,int>> top = minh.top();
        res.push_back(top.first);
        minh.pop();

        int row = top.second.first;
        int col = top.second.second;

        if(col+1 < kArrays[row].size()){
            int val = kArrays[row][col+1];
            minh.push(make_pair(val,make_pair(row,col+1)));
        }
    }
    return res;
}
