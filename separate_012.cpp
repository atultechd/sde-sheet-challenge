#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    vector<int> temp;
    for(int i=0; i<n; i++){
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
    
}