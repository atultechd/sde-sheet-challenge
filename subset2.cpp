#include<bits/stdc++.h>

void find_subsets(int ind, vector<vector<int>> &ans, vector<int> &res,vector<int> &arr){
    ans.push_back(res);
    for(int i=ind; i<arr.size(); i++){
        if(i != ind && arr[i] == arr[i-1])continue;
        res.push_back(arr[i]);
        find_subsets(i+1,ans,res,arr);
        res.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> res;
    sort(arr.begin(), arr.end());
    find_subsets(0,ans,res,arr);
    return ans;
}