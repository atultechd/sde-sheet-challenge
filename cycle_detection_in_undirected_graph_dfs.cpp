#include<bits/stdc++.h>

bool is_cyclic_dfs(int node, int parent, unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj){

    vis[node] = true;

    for(auto neighbour: adj[node]){

        if(!vis[neighbour]){

            bool cycle_detected = is_cyclic_dfs(neighbour, node, vis, adj);

            if(cycle_detected) return true;

        }
        else if(neighbour != parent){

            return true;
        }
    }

    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m){

    unordered_map<int,list<int>> adj;

    for(int i=0; i<m; i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int,bool> vis;

    for(int i=0; i<n; i++){

        if(!vis[i]){

            bool ans = is_cyclic_dfs(i, -1, vis, adj);
            if(ans) return "Yes";
        }
    }
    
    return "No";
}
