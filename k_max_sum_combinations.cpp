#include<bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int> res;
  priority_queue<int> maxh;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maxh.push(a[i]+b[j]);
        }
    }
    for(int i=0; i<k; i++){
        int num = maxh.top();
        maxh.pop();
        res.push_back(num);
    }
    return res;
    
}