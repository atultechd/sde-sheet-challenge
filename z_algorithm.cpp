int zAlgorithm(string s, string p, int n, int m)
{
    int count = 0;
    for(int i=0; i<n-m+1; i++){
        string res = s.substr(i, m);
        if(res == p) count++;
    }
    return count;
}