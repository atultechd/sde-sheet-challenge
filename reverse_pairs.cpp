#include <bits/stdc++.h> 

int merge(vector<int> &arr, int s, int m, int e){
    int n1 = m-s+1;
    int n2 = e-m;
    int l_arr[n1], r_arr[n2];
    for(int i=0; i<n1; i++) l_arr[i] = arr[s+i];
    for(int i=0; i<n2; i++) r_arr[i] = arr[m+1+i];
    int count = 0;
    int j=0;

    // to calculate the count of reverse pair;
    for(int i=0; i<n1; i++){
        while(j<n2 && (l_arr[i] > 2LL*r_arr[j])){
            j++;
        }
        count += j;
    }
    //    ...........................
    int i=0, k=s;
    j=0;
    while(i<n1 && j<n2){
        if(l_arr[i] <= r_arr[j]) arr[k++] = l_arr[i++];
        else arr[k++] = r_arr[j++];
    }
    while(i<n1) arr[k++] = l_arr[i++];
    while(j<n2) arr[k++] = r_arr[j++];
    
    return count;
}

int mergesort(vector<int> &arr, int start, int end){
    if(start >= end) return 0;
    int mid = (start+end)/2;
    int count = 0;
    count += mergesort(arr, start, mid);
    count += mergesort(arr, mid+1, end);
    count += merge(arr,start,mid,end);
    return count;
}

int reversePairs(vector<int> &arr, int n){
    return mergesort(arr, 0, n-1);
}