
void expand(string s, int l, int r, string &res, int &res_len ){
    while(l>=0 && r<s.length() && s[l] == s[r]){
        if(r-l+1 > res_len){
            res_len = r-l+1;
            res = s.substr(l, r-l+1);
        }
        l--, r++;
    }
}

string longestPalinSubstring(string str){
    string res ="";
    int res_len = 0;
    int n=str.length();
    for(int i=0; i<n; i++){
        expand(str,i,i,res,res_len);
        expand(str,i,i+1,res,res_len);
    }
    return res;
}