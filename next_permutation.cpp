 vector<int> nextPermutation(vector<int> &permutation, int n){
    int i;
    for(i= n-2; i>=0; i--){
        if(permutation[i] < permutation[i+1]) break;
    }   
    if(i>=0){
        int j = permutation.size()-1;
        while(permutation[i] >= permutation[j]) j--;
        swap(permutation[i], permutation[j]);
        reverse(permutation.begin()+i+1,permutation.end());
        return permutation;
    }
    reverse(permutation.begin(),permutation.end());
    return permutation;
}