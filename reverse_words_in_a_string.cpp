string reverseString(string str)
{
    string ans = "";
    for(int i=str.size()-1; i>=0; i--){
        if(str[i] == ' ') continue;
        int j=i;
        while(j>=0 && str[j] != ' '){
            j--;
        }
        ans += (str.substr(j+1, i-j));
        ans += ' ';
        i = j;
    }
    return ans;
}