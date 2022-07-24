// Recursive approach
int solve(int ind, int n, vector<int> &price){

    if(ind==0) return n*price[0];

    int not_take = 0 + solve(ind-1,n,price);

    int take = INT_MIN;

    int rod_len = ind+1;

    if(rod_len <= n){

        take = price[ind] + solve(ind, n-rod_len, price);
    }

    return max(take,not_take);
}


int cutRod(vector<int> &price, int n){

  return solve(n-1, n, price);
}

// .......................................................................

// Memoization approach
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp){

    if(ind==0) return n*price[0];

    if(dp[ind][n] != -1) return dp[ind][n];

    int not_take = 0 + f(ind-1,n,price,dp);

    int take = INT_MIN;

    int rod_len = ind+1;

    if(rod_len <= n){

        take = price[ind] + f(ind, n-rod_len, price,dp);
    }

    return dp[ind][n] = max(take,not_take);
}

int cutRod(vector<int> &price, int n){

    vector<vector<int>> dp(n, vector<int>(n+1, -1));

  return f(n-1, n, price, dp);
}

// ..........................................................................

// Bottom-Up approach
int cutRod(vector<int> &price, int n){

    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    for(int i=0; i<=n; i++){

        dp[0][i] = i* price[0];
    }

    for(int ind = 1; ind < n; ind++){

        for(int N = 0; N <= n; N++){

            int not_take = 0 + dp[ind-1][N];

            int take = INT_MIN;

            int rod_len = ind+1;

            if(rod_len <= N){

                take = price[ind] + dp[ind][N-rod_len];
            }

            dp[ind][N] = max(take,not_take);
        }
    }

  return dp[n-1][n];
}

// ..........................................................................

// Space optimization
int cutRod(vector<int> &price, int n){

    vector<int> prev(n+1,0), cur(n+1,0);

    for(int i=0; i<=n; i++){

        prev[i] = i* price[0];
    }

    for(int ind = 1; ind < n; ind++){

        for(int N = 0; N <= n; N++){

            int not_take = 0 + prev[N];

            int take = INT_MIN;

            int rod_len = ind+1;

            if(rod_len <= N){

                take = price[ind] + cur[N-rod_len];
            }

            cur[N] = max(take,not_take);
        }

        prev = cur;
    }
    
  return prev[n];
}
