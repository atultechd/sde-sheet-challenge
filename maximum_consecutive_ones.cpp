int longestSubSeg(vector<int> &arr , int n, int k){
    int res = 0, zero_count = 0, i = -1;
    for(int j=0; j<n; j++){
        if(arr[j] == 0) zero_count++;
        while(zero_count>k){
            i++;
            if(arr[i] == 0) zero_count--;
        }
        int length = j - i;
        if(length > res) res = length;
    }
    return res;
}
