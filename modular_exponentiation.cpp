#include <bits/stdc++.h> 
int modularExponentiation(int a, int b, int m) {
    int ans =1;
    while(b){
      // To check whether once place bit is 1 or not.
        if(b&1){
            ans = (ans * 1LL * a) % m;
        }
        // If not 1 then just raise power of b but don't add it to ans.
        a = (1LL * a * a) % m;
        // right shift to b for each and every place bit.
        b >>= 1;
    }
    
    return ans;
}