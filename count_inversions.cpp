#include <bits/stdc++.h>
long long int res = 0;

void merge(long long *arr, long long l, long long m, long long r){
    long long n1 = m-l+1, n2 = r-m;
    long long l_arr[n1], r_arr[n2];
    for(long long i=0; i<n1; i++){
        l_arr[i] = arr[l+i];
    }
    for(long long i=0; i<n2; i++){
        r_arr[i] = arr[m+i+1];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(l_arr[i] <= r_arr[j]){
            arr[k++] = l_arr[i++];
        }
        else{
            arr[k++] = r_arr[j++];
            res += (n1-i);
        }
    }
    while(i<n1){
        arr[k++] = l_arr[i++];
    }
    while(j<n2){
        arr[k++] = r_arr[j++];
    }
}

void mergesort(long long *arr, long long left, long long right){
    if(left >= right) return;
    long long mid = (left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
    
}
long long getInversions(long long *arr, int n){
    mergesort(arr,0,n-1);
    return res;
}