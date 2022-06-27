

void solve(vector<int> &v,vector<vector<int>> &res,vector<int> &subset, int ind){
    if(ind==v.size()){
        res.push_back(subset);
        return;
    }
    subset.push_back(v[ind]);
    solve(v,res,subset,ind+1);
    
    subset.pop_back();
    solve(v,res,subset,ind+1);
}

vector<vector<int>> pwset(vector<int>v){
    vector<vector<int>> res;
    vector<int> subset;
    solve(v,res,subset,0);
    return res;
}