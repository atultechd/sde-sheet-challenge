#include<bits/stdc++.h>

bool dfs(int node, unordered_map<int,list<int>> &adj, vector<int> &color){

    for(auto neighbour : adj[node]){

        if(color[neighbour] == -1){

            color[neighbour] = 1-color[node];

            if(!dfs(neighbour,adj,color))return false;
        }

        else if(color[neighbour] == color[node])return false;
    }

    return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {

  unordered_map<int,list<int>> adj;

    int n = edges.size();

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(edges[i][j] == 1){

                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(n,-1);

    for(int i=0; i<n; i++){

        if(color[i] == -1){

            color[i] = 1;

            if(!dfs(i,adj,color)) return false;
        }
    }
    
    return true;
    
}