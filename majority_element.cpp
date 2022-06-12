#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int element = arr[0], count = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == element) count++;
        else count--;
        if(count == 0){
            element = arr[i];
            count = 1;
        }
    }
    count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == element){
            count++;
        }
    }
    if(count > n/2) return element;
    return -1;
}