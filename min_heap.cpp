#include<bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    multiset<int>ms;
    vector<int> res;
    for(auto &it : q){
        if(it[0] == 1){
            auto a = ms.begin();
            res.push_back(*a);
            ms.erase(a);
        }
        else{
            ms.insert(it[1]);
        }
    }
    return res;
}
