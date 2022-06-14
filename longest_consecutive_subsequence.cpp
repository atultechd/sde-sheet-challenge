#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int res = INT_MIN;
    if(n==0)return 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++) m[arr[i]]++;
    for(auto j:arr){
        if(m.find(j-1) == m.end()){
            int k = j;
            int len = 1;
            while(m.find(k+1) != m.end()){
                k++;
                len++;
            }
            res = max(res, len);
        }
    }
    return res>0 ? res : 1;
}


// vector<int> arr = {32, 25, 33, 30, 34};

// output : res = 3 ( 32 -> 33 -> 34 longest consecutive subsequence in given array);