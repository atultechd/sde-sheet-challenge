
bool is_palindrome(string s, int start, int end){
    while(start<= end){
        if(s[start++]!=s[end--]) return false;
    }
    return true;
}

void funct(int index, string s, vector<string> &path, vector<vector<string>> &res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index; i<s.size(); i++){
        if(is_palindrome(s,index,i)){
            path.push_back(s.substr(index, i-index+1));
            funct(i+1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> res;
    vector<string> path;
    funct(0,s,path,res);
    return res;
}

