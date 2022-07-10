
// Brute force, T.L.E , TC: O(2^n)
int solve(string s, int s_len, string t, int t_len){
    if(s_len == 0 || t_len == 0) return 0;
    if(s[s_len -1] == t[t_len -1])
        return 1 + solve(s, s_len-1, t, t_len-1);
    else
        return max(solve(s, s_len-1, t, t_len), solve(s, s_len, t, t_len-1));
}

int lcs(string s, string t){
    int s_len = s.length();
    int t_len = t.length();
    return solve(s,s_len,t,t_len);
}



// Optimised Approach, TC: O(n * m)    ..[n = s_len, m = t_len]
#include<bits/stdc++.h>
int solve(string &s, int s_len, string &t, int t_len, vector<vector<int>> &dp){
    if(s_len == 0 || t_len == 0) return 0;
    if(dp[s_len][t_len] != -1) return dp[s_len][t_len];
    if(s[s_len -1] == t[t_len -1])
        return dp[s_len][t_len] = 1 + solve(s, s_len-1, t, t_len-1, dp);
    else
        return dp[s_len][t_len] = max(solve(s, s_len-1, t, t_len, dp), solve(s, s_len, t, t_len-1, dp));
}

int lcs(string s, string t){
    int s_len = s.length();
    int t_len = t.length();
    vector<vector<int>> dp(s_len+1, vector<int>(t_len+1, -1));
    for(int i=0; i<=s_len; i++){
        dp[i][0] = 0;     
    }
    for(int i=0; i<=t_len; i++){
        dp[0][i] = 0;     
    }
    return solve(s,s_len,t,t_len,dp);
}