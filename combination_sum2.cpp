void sort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void solve(vector<int> &arr, int target, vector<vector<int>> &res, vector<int> &ans,int k){
    if(target == 0){
        res.push_back(ans);
        return;
    }
    for(int i=k; i<arr.size(); i++){
        if(i > k && arr[i]==arr[i-1]) continue;
        if(arr[i] <= target){
            ans.push_back(arr[i]);
            solve(arr,target-arr[i],res,ans,i+1);
            ans.pop_back();
        }     
    }
    
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
  vector<vector<int>> res;
    vector<int> ans;
    sort(arr);
    solve(arr,target,res,ans,0);
    return res;
}
