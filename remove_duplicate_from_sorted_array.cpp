int removeDuplicates(vector<int> &arr, int n) {
    if(n == 0) return 0;
    int k = 0;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[k]){
            k++;
            arr[k] = arr[i];
        }
    }
    return k+1;
}