
string find_prefix(string ans, string check){
    if(ans.size() > check.size()) swap(ans,check);
    string res = "";
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == check[i]) res += (char)ans[i];
        else break;
    }
    return res;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = arr[0];
    for(int i=1; i<n; i++){
        ans = find_prefix(ans, arr[i]);
    }
    return ans;
}