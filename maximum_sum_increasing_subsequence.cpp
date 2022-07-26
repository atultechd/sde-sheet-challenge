int maxIncreasingDumbbellsSum(vector<int> &rack, int n){

    int dp[n];

    for(int i=0; i<n; i++){

        dp[i] = rack[i];
    }

    for(int i=0; i<n; i++){

        for(int j=0; j<i; j++){

            if(rack[j] < rack[i]){

                dp[i] = max(dp[i], rack[i]+dp[j]);
            }
        }
    }
    int maxi = 0;

    for(int i=0; i<n; i++){

        maxi = max(dp[i], maxi);
    }
   
    return maxi;
}