#include <bits/stdc++.h> 
int uniqueSubstrings(string input){
    vector<int> freqchar(26,0);
    int max_len = 1, i=0, j=0;
    int n=input.size();
    while(j < n){
        if(freqchar[input[j]-'a']==0){
            freqchar[input[j]-'a']=1;
        }
        else{
            max_len = max(max_len, j-i);
            while(i <= j && freqchar[input[j]-'a'] > 0){
                freqchar[input[i]-'a'] = 0;
                i++;
            }
            freqchar[input[j]-'a'] = 1;
        }
        j++;
    }
    max_len = max(max_len, j-i);
    return max_len;
}