bool findPattern(string p, string s)
{
    int l1 = s.length();
    int l2 = p.length();
    for(int i=0; i<l1-l2+1; i++){
        if(p[0] == s[i]){
            string new_s = s.substr(i, l2);
            if(new_s == p) return true;
        }
    }
    return false;
}