#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

    int max_len = 0, curr_sum = 0;
    unordered_map<int,int> m;
    for(int i=0; i<arr.size(); i++){
        curr_sum += arr[i];
        if(curr_sum == 0){
            max_len = i+1;
        }
        else{
            if(m.find(curr_sum) != m.end()){
                max_len = max(max_len, i-m[curr_sum]);
            }
            else{
                m[curr_sum] = i;
            }
        }
    }
    return max_len;

}