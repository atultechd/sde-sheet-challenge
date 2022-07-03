#include<bits/stdc++.h>
int return_modulus(int a, int b){
    if(a > b) return a-b;
    else return b-a;
}
int romanToInt(string s) {
    map<char,int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
   
    vector<int> res;
    for(int i=0; i<s.length(); i++){
        int a = mp[s[i]];
        res.push_back(a);
    }
    int sum = 0;
    int n = res.size();
    for(int j=0; j<n-1; j++){
        if(res[j] >= res[j+1]) sum += res[j];
        else sum -= res[j];
    }
    sum = sum + res[n-1];
    return sum;
}
