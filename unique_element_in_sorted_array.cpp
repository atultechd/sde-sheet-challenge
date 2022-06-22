#include<bits/stdc++.h>

// TC: O(n), SC: O(1)

int uniqueElement(vector<int> arr, int n){
    int xorr=0;
    for(int i=0; i<n; i++){
        xorr ^= arr[i];
    }
    return xorr;
}

// 2 same numbers ka xor hamesha zero hota hai that is why
// jo bhi element double thay zero ho gaye
// aur end me ans mil gaya
