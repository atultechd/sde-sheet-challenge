#include<bits/stdc++.h>


vector<int> next_smaller(vector<int> &a, int n){
    vector<int> res(n,n);
    stack<pair<int,int>> s;
    s.push({a[n-1], n-1});
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && s.top().first >= a[i]){
            s.pop();
        }
        if(!s.empty()) res[i] = s.top().second;
        s.push({a[i], i});
    }
    return res;
}


vector<int> prev_smaller(vector<int> &a, int n){
    vector<int> res(n,-1);
    stack<pair<int,int>> s;
    s.push({a[0], 0});
    for(int i=1; i<n; i++){
        while(!s.empty() && s.top().first >= a[i]){
            s.pop();
        }
        if(!s.empty()) res[i] = s.top().second;
        s.push({a[i], i});
    }
    return res;
}


vector<int> maxMinWindow(vector<int> a, int n) {

    vector<int> ns = next_smaller(a,n);
    vector<int> ps = prev_smaller(a,n);
    vector<int> ans(n, INT_MIN);

    for(int i=0; i<n; i++){
        int length = (ns[i]-ps[i]-1)-1;
        if(a[i] > ans[length]) ans[length] = a[i];
    }   

    for(int i=n-2; i>=0; i--){
        if(ans[i] < ans[i+1]) ans[i] = ans[i+1];
    }
    return ans;
}