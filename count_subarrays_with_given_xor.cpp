
#include<bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x){
    map<int,int> freq;
    int xorr = 0, count = 0;
    for(auto i: arr){
        xorr = xorr ^ i;
        if(xorr == x) count++;
        if(freq.find(xorr ^ x) != freq.end()) count += freq[xorr ^ x];
        freq[xorr] += 1;
    }
    return count;
}