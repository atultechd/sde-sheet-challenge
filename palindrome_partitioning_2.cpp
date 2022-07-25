#include<bits/stdc++.h>

bool is_palindrome(int i, int j, string &str){

    while(i<j){

        if(str[i] != str[j]) 

            return false;

        i++;
        j--;
    }
    return true;
}

int f(int i, int n, string &str,vector<int> &dp){

    if(i==n) return 0;

    if(dp[i] != -1) return dp[i];

    int mincost = 1e8;

    for(int j=i; j<n; j++){

        if(is_palindrome(i,j,str)){

            int cost = 1+ f(j+1,n,str,dp);

            mincost = min(mincost, cost);
        }
    }
    return dp[i] = mincost;
}

int palindromePartitioning(string str) {

    int n = str.size();

    vector<int> dp(n,-1);

    return (f(0,n,str,dp) - 1);
}

// ........................................................................

#include<bits/stdc++.h>

bool is_palindrome(int i, int j, string &str){

    while(i<j){

        if(str[i] != str[j]) 

            return false;

        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {

    int n = str.size();

    vector<int> dp(n+1,0);

    dp[n] = 0;

    for(int i= n-1; i>=0; i--){

        int mincost = 1e8;

        for(int j=i; j<n; j++){

            if(is_palindrome(i,j,str)){

                int cost = 1+ dp[j+1];

                mincost = min(mincost, cost);
            }
        }
        
        dp[i] = mincost;
    }
    return dp[0]-1;
}
