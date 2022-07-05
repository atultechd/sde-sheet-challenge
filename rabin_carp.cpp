vector<int> stringMatch(string &str, string &pat) {
    vector<int> ans;
    int s = str.length();
    int p = pat.length();
    for(int i = 0; i < s-p+1; i++){
        if(pat[0] == str[i]){
            string new_str = str.substr(i, p);
            if(new_str == pat){
                ans.push_back(i);
            }
        }
    }
    return ans;
}
