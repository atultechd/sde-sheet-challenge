void solve(string &s, vector<string>&res, int i){
    if(i == s.size()){
        res.push_back(s);
        return;
    }
    for(int k=i; k<s.size(); k++){
        swap(s[i], s[k]);
        solve(s,res,i+1);
        swap(s[i], s[k]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string>res;
    solve(s,res,0);
    return res;
}