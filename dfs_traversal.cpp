#include<bits/stdc++.h>

void dfs(vector<int> adj[], int node, vector<int> &arr, vector<int> &vis){

    arr.push_back(node);

    vis[node] = 1;

    for(auto it: adj[node]){

        if(!vis[it]) dfs(adj,it,arr,vis);
    }
}


vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges){

    vector<int> adj[v];

    vector<int> vis(v,0);

    vector<vector<int>> ans;

    for(int i=0; i<e; i++){

        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for(int i=0; i<v; i++){

        if(!vis[i]){

            vector<int> arr;

            dfs(adj, i, arr, vis);

            ans.push_back(arr);
        }
    }

    return ans;
}