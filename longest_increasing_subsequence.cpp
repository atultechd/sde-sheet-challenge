#include<bits/stdc++.h>

// Brute force TLE..
int solve_lis(int arr[], int i){

    int ans = 1;

    for(int j = 0; j< i; ++j){

        if(arr[i] > arr[j]){

            ans = max(ans, solve_lis(arr,j) + 1);
        }
    }
    return ans;
}

int longestIncreasingSubsequence(int arr[], int n){

    int ans = 0;

    for(int i=0; i<n; i++){

        ans = max(ans, solve_lis(arr,i));

    }
    return ans;
}

// ..............................................................................

// optimised solution
int solve_lis(int dp[], int arr[], int i){

    if (dp[i] != -1) return dp[i];

    int ans = 1;

    for(int j = 0; j< i; ++j){

        if(arr[i] > arr[j]){

            ans = max(ans, solve_lis(dp,arr,j) + 1);
        }
    }
    return dp[i] = ans;
}


int longestIncreasingSubsequence(int arr[], int n){

    int dp[n];

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for(int i=0; i<n; i++){

        ans = max(ans, solve_lis(dp, arr,i));
    }
    return ans;
}

// ..............................................................................

// most optimised using binary search.
int longestIncreasingSubsequence(int arr[], int n){

    vector<int> temp;

    temp.push_back(arr[0]);

    int sizee = 1;

    for(int i=1; i<n; i++){

        if(arr[i] > temp.back()){

            temp.push_back(arr[i]);

            sizee ++;
        }
        else{

            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            
            temp[ind] = arr[i];
        }
    }
    return sizee;
}
