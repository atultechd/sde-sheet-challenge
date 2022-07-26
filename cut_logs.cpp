#include<bits/stdc++.h>

// Memoization approach 
int solve_for_cutlogs(int number_of_axes, int stand_capacity, vector<vector<int>> &dp){

    if(stand_capacity==0 || stand_capacity==1 || number_of_axes==1) return stand_capacity;

    if(dp[number_of_axes][stand_capacity] != -1) return dp[number_of_axes][stand_capacity];

    int ans = INT_MAX;

    int l=1;

    int h=stand_capacity;

    while(l<=h){

        int mid = (l+(h-l)/ 2);

        int axe_break = solve_for_cutlogs(number_of_axes-1, mid-1,dp);

        int not_break = solve_for_cutlogs(number_of_axes, stand_capacity-mid,dp);

        int temp = 1 + max(axe_break, not_break);

        if(axe_break < not_break) l = mid+1;

        else h = mid-1;

        ans = min(ans,temp);
    }

    return dp[number_of_axes][stand_capacity] = ans;
}


int cutLogs(int k, int n){

    vector<vector<int>> dp(101, vector<int>(10001, -1));

    return solve_for_cutlogs(k,n,dp);
}
