
#include<bits/stdc++.h>

vector<int> countDistinctElements(vector<int> &arr, int k) {

    int n = arr.size();

    vector<int> res;
    map<int,int> m;

    for(int i=0; i< k; i++){

        m[arr[i]]++;

    }
    res.push_back(m.size());

    for(int i=k; i<n; i++){

        m[arr[i-k]]--;

        if(m[arr[i-k]] == 0) m.erase(arr[i-k]);

        m[arr[i]]++;

        res.push_back(m.size());
    }

    return res;
}
