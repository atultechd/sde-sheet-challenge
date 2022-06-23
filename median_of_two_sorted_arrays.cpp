#include<bits/stdc++.h>

// TC: O(nlogn), SC: O(1)
double median(vector<int> a, vector<int> b){

    for(int i=0; i<b.size(); i++){
        a.push_back(b[i]);
    }
    sort(a.begin(), a.end());
    
    int mid = a.size()>>1;
    
    // If array a is even sized then median should be the
    // mean of two middle elements.
    if(a.size() % 2 == 0){
        return (double)((a[mid-1]+a[mid])/2.0);
    }
    // if size is odd then the middle element should be median.   
    return (double)(a[mid]); 
}


// 
