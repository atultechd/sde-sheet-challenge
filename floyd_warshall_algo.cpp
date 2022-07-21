#include<bits/stdc++.h>

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<vector<int>> adj(n+1, vector<int>(n+1, 1e9));

    for(auto it: edges){

        adj[it[0]][it[1]] = it[2];
    }
    
    int n1 = n+1;

    while(n1--){

        adj[n1][n1] = 0;

    }

    for(int k=1; k<=n; k++){

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){

                if((adj[i][k] != 1e9 && adj[k][j] != 1e9) && (adj[i][k] + adj[k][j] < adj[i][j])){

                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    
    return adj[src][dest];
}