#include <bits/stdc++.h> 

// solution with time complexity : O(n) ans space : O(n)
long getTrappedWater(long *arr, int n){
    long left[n], right[n];
    left[0] = arr[0];
    for(int i=1; i<n; i++){
        left[i] = max(arr[i], left[i-1]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = max(right[i+1], arr[i]);
    }
    long ans = 0;
    for(int i=0; i<n; i++){
        ans += (min(left[i], right[i]) - arr[i]);
    }
    return ans;
}


// optimal solution with time complexity : O(n) ans space : O(1)
long getTrappedWater(long *arr, int n){
    long left = 0, right = 0;
    int i=0, j=n-1;
    long ans = 0;
    while(i<j){
        left = max(left, arr[i]);
        right = max(right, arr[j]);
        if(left < right){
            ans += (left-arr[i]);
            i++;
        }
        else{
            ans += (right-arr[j]);
            j--;
        }
    }
    return ans;
}