#include<bits/stdc++.h>

// tc: O(n), sc: O(n).....

// int calculateMinPatforms(int at[], int dt[], int n) {
//     int platform[2361] = {0};
//     int count = 1;
//     for(int i=0; i<n; i++){
//         ++platform[at[i]];
//         --platform[dt[i]+1];
//     }    
//     for(int i=1; i<2361; i++){
//         platform[i] = platform[i] + platform[i-1];
//         count = max(count, platform[i]);
//     }
        
//     return count;
// }


// This approach is more optimised...tc: O(nlogn), sc: O(1)

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    int platform_needed = 1, res = 1;
    int i=1, j=0;
    while(i<n && j<n){
        if(at[i] <= dt[j]){
            platform_needed++;
            i++;
        }
        else if(at[i] > dt[j]){
            platform_needed--;
            j++;
        }
        if(platform_needed > res){
            res = platform_needed;
        }
    }
        
    return res;
}