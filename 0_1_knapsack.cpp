// Brute force solution TLE.
int solve(vector<int> &values, vector<int> &weights, int index, int capacity){

    if(index == 0){

        if(weights[0] <= capacity){

            return values[0];
        }

        else return 0;
    }   

    int include = 0;

    if(weights[index] <= capacity){

        include = values[index] + solve(values,weights,index-1,capacity-weights[index]);
    }

    int exclude = solve(values,weights,index-1,capacity);

    int res = max(include, exclude);

    return res;
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){

  return solve(values,weights,n-1,w);
}


// ....................................................................................................

// More optimised using Memoization.
int solve_memo(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>> &dp){

    if(index == 0){

        if(weights[0] <= capacity){

            return values[0];
        }

        else return 0;
    }   
    
    if(dp[index][capacity] != -1) return dp[index][capacity];
    
    int include = 0;

    if(weights[index] <= capacity){

        include = values[index] + solve_memo(values,weights,index-1,capacity-weights[index],dp);
    }

    int exclude = solve_memo(values,weights,index-1,capacity,dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){

    vector<vector<int>> dp(n, vector<int>(w+1, -1));

  return solve_memo(values,weights,n-1,w,dp);
}


// .............................................................................................

 
// Tabularization approach

int solve_tab(vector<int> &values, vector<int> &weights, int n, int capacity){

    vector<vector<int>> dp(n,vector<int>(capacity+1,0));
    
    for(int w = weights[0]; w<= capacity; w++){

        if(weights[0] <= capacity) dp[0][w] = values[0];

        else dp[0][w] = 0;
    }
    
    for(int index = 1; index < n; index++){

        for(int w = 0; w<= capacity; w++){

            int include = 0;

            if(weights[index] <= w){

                include = values[index] + dp[index-1][w-weights[index]];
                }

            int exclude = dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
} 


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
  return solve_tab(values,weights,n,w);
}