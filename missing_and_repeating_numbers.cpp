#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    pair<int,int> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            ans.second = arr[i];
        }
    }
    int a[n+1] = {0};
    for(auto b:arr){
        a[b]++;
    }
    for(int i=1; i<n+1; i++){
        if(a[i] == 0){
            ans.first = i;
        }
    }
    
    return ans;
}
