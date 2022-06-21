

void solve(int start, string &s, vector<string> &dict, vector<string> &res, string &str){
    if(start >= s.size()){
        res.push_back(str);
        return;
    }
    for(int i=start; i<s.size(); i++){
        string tmp = s.substr(start, i-start+1);
        bool is_present = false;
        for(string it: dict){
            if(it.compare(tmp) == 0){
                is_present = true;
                break;
            }
        }
        if(is_present){
            string x = str;
            str += tmp + " ";
            solve(i+1,s,dict,res,str);
            str = x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dict){
    vector<string> res;
    string str;
    solve(0,s,dict,res,str);
    return res;
}