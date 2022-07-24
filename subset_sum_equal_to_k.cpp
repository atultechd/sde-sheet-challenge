// Recursive solution
bool solve(int index, int target, vector<int> &arr){

    if(target == 0) return true;

    if(index==0) return (arr[0] == target);

    bool not_take = solve(index-1, target,arr);

    bool take = false;

    if(target >= arr[index]){

        take = solve(index-1, target-arr[index], arr);
    }

    return take || not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    return solve(n-1,k,arr);
}

// .......................................................................

// Memoization approach 
bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){

    if(target == 0) return true;

    if(index==0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    bool not_take = f(index-1, target,arr,dp);

    bool take = false;

    if(target >= arr[index]){

        take = f(index-1, target-arr[index], arr,dp);
    }

    return dp[index][target] = take || not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return f(n-1,k,arr,dp);
}


// .....................................................................

// Bottom-up (tabulation) approach
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    for(int i=0; i<n; i++) dp[i][0] = true;

    dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){

        for(int target = 1; target <= k; target++){

            bool not_take = dp[ind-1][target];

            bool take = false;

            if(target >= arr[ind]){

                take = dp[ind-1][target-arr[ind]];
            }

            dp[ind][target] = take || not_take;
        }
    }

    return dp[n-1][k];
}


// ..........................................................................

// Most optimised(instead of 2d vector we just use 2 1d vector).

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1,0), cur(k+1,0);

    prev[0] = cur[0] = true; 

    prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++){

        for(int target = 1; target <= k; target++){

            bool not_take = prev[target];

            bool take = false;

            if(target >= arr[ind]){

                take = prev[target-arr[ind]];
            }

            cur[target] = take || not_take;
        }

        prev = cur;
    }
    
    return prev[k];
}