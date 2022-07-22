int maximumProduct(vector<int> &arr, int n){

    int res = arr[0];

    int maxi = res;
    
    int mini = res;
    
    for(int i=1; i<n; i++){
        if(arr[i] < 0) swap(maxi, mini);
        maxi = max(arr[i], maxi*arr[i]);
        mini = min(arr[i], mini*arr[i]);
        res = max(res,maxi);
    }
    
    return res;
}
