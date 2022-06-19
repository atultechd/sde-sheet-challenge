#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    int platform[2361] = {0};
    int count = 1;
    for(int i=0; i<n; i++){
        ++platform[at[i]];
        --platform[dt[i]+1];
    }    
    for(int i=1; i<2361; i++){
        platform[i] = platform[i] + platform[i-1];
        count = max(count, platform[i]);
    }
        
    return count;
}