#include<bits/stdc++.h>

bool check_cycle_dfs(int node, unordered_map<int,bool> &vis, unordered_map<int,bool> &dfs_vis, unordered_map<int,list<int>> &adj){

    vis[node] = true;

    dfs_vis[node] = true;

    for(auto neighbour : adj[node]){

        if(!vis[neighbour]){

            bool cycle_detected = check_cycle_dfs(neighbour, vis, dfs_vis, adj);

            if(cycle_detected) return true;

        }
        else if(dfs_vis[neighbour]) return true;

    }
    dfs_vis[node] = false;

    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);

    }

    unordered_map<int,bool> vis;

    unordered_map<int,bool> dfs_vis;

    for(int i=1; i<=n; i++){

        if(!vis[i]){

            bool cycle_found = check_cycle_dfs(i, vis, dfs_vis, adj);
            
            if(cycle_found) return true;
        }
    }
    return false;
}