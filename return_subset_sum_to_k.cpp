#include<bits/stdc++.h>

void solve(int ind,vector<int> &arr, int n, int target, vector<vector<int>> &res, vector<int> &ds){
    if(ind == n){
        if(target==0){
            res.push_back(ds);   
        }
        return;
    }
    else{
        ds.push_back(arr[ind]);
        solve(ind+1,arr,n,target-arr[ind],res,ds);
        ds.pop_back();  
        solve(ind+1,arr,n,target,res,ds);
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> ds;
    solve(0,arr,n,k,res,ds);
    return res;
}