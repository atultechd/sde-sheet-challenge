
#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr){

    unordered_map<int,int> mp;
    vector<vector<int>> frequency(arr.size());
    vector<int> res;
    for(int i:arr){
        mp[i]++;
    }
    for(pair<int,int> i:mp){
        int first = i.first;
        int second = i.second;

        frequency[second].push_back(first);
    }
    int counter = 0;
    for(int i = frequency.size()-1; i >= 0; i--){
        vector<int> v = frequency[i];
        for(int j = 0; j<v.size() && counter<k; j++){
            res.push_back(v[j]);
            counter++;
        }
    }
    sort(res.begin(), res.end());
    
    return res;
    
}