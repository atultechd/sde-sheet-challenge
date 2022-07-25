#include<bits/stdc++.h>

int f(int i, set<string> &arr, string &target){

    if(i==target.size()) return 1;

    string temp = "";

    for(int j=i; j<target.size(); j++){

        temp += target[j];

        if(arr.find(temp) != arr.end()){

            if(f(j+1,arr,target)) return 1;
        }
    }
    return 0;
}

bool wordBreak(vector<string> &arr, int n, string &target) {

    set<string> st;

    for(auto a: arr) st.insert(a);

    return f(0,st,target);
}

// .....................................................................

int f(int i, set<string> &arr, string &target, vector<int> &dp){

    if(i==target.size()) return 1;

    if(dp[i] != -1) return dp[i];

    string temp;

    for(int j=i; j<target.size(); j++){

        temp += target[j];

        if(arr.find(temp) != arr.end()){

            if(f(j+1,arr,target,dp)) return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}

bool wordBreak(vector<string> &arr, int n, string &target) {

    vector<int> dp(1001,-1);

    set<string> st;

    for(auto a: arr) st.insert(a);

    return f(0,st,target,dp);
}

// .....................................................................


bool wordBreak(vector<string> &arr, int n, string &target) {

    vector<bool> dp(target.size()+1);

    set<string> st;

    for(auto a: arr) st.insert(a);

    int t = target.size();

    dp[t] = true;

    for(int i = t-1; i >= 0; i--){

        string temp;

        for(int j = i; j < t; j++){

            temp += target[j];

            if(st.find(temp) != st.end()){

                dp[i] = dp[j+1];
                
                break;
            }
        }
    }
    return dp[0];
}