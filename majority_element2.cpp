#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> res;
    int maxof = 0, n = arr.size() ;
    for(int i=0; i<arr.size(); i++){
        maxof = max(arr[i], maxof);
    }
    int count[maxof+1] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    for(int i=0; i<maxof+1; i++){
        if(count[i] > n/3){
            res.push_back(i);
        }
    }
    return res;
}