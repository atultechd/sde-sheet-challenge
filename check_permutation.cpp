#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    if(str1.size() != str2.size()) return false;
    map<char,int>m;
    for(int i=0; i<str1.size(); i++){
        m[str1[i]] = 1;
    }
    for(int i=0; i<str2.size(); i++){
        if(m.find(str2[i]) == m.end()) return false;
    }
    return true;
}