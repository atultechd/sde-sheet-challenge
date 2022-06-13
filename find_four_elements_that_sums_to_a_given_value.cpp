#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int,pair<int,int>> m;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int map_fill = arr[i] + arr[j];
            m[map_fill] = {i,j};
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int left_out = target - (arr[i] + arr[j]);
            if(m.find(left_out) != m.end()){
                pair<int,int> it = m[left_out];
                int k = it.first;
                int l = it.second;
                if(i != k && i != l && j != k && j != l){
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
