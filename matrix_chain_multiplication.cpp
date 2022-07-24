// Recursive solution TLE...
int fx(int i, int j, vector<int> &arr){

    if(i==j) return 0;

    int mini = 1e9;

    for(int k=i; k<j; k++){

        int cost = arr[i-1]*arr[k]*arr[j] + fx(i,k,arr)+ fx(k+1,j,arr);

        if(cost < mini) mini = cost;
    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N){

    return fx(1,N-1,arr);
}

// ..........................................................................

// Optimised solution using memoization method,
int fx(int i, int j, vector<int> &arr, vector<vector<int>> &dp){

    if(i==j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;

    for(int k=i; k<j; k++){

        int cost = arr[i-1]*arr[k]*arr[j] + fx(i,k,arr,dp)+ fx(k+1,j,arr,dp);

        if(cost < mini) mini = cost;
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N){

    vector<vector<int>> dp(N, vector<int>(N,-1));

    return fx(1,N-1,arr,dp);
}

// ..........................................................................


// More optimised solution using bottom up (tabulation) approach.

int matrixMultiplication(vector<int> &arr, int N){

    int dp[N][N];

    for(int i=1; i<N; i++) dp[i][i] = 0;

    for(int i=N-1; i>=1; i--){

        for(int j=i+1; j<N; j++){

            int mini = 1e9;

            for(int k=i; k<j; k++){

                int cost = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                if(cost < mini) mini = cost;
            }

            dp[i][j] = mini;
        }
    }
    
    return dp[1][N-1];
}