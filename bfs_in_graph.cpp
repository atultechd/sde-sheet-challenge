#include<bits/stdc++.h>

void bfs(int v,map<int,set<int>> &adj, vector<int> &vis, vector<int> &res){

    queue<int> q;

    q.push(v);

    while(!q.empty()){

        int curr = q.front();

        q.pop();

        res.push_back(curr);

        for(auto it: adj[curr]){

            if(!vis[it]){

                vis[it] = 1;
                q.push(it);
            }
        }
    }
}


vector<int> BFS(int vtx, vector<pair<int, int>> edges){

    vector<int>vis(vtx,0);

    vector<int> res;

    map<int,set<int>> adj;
    
    for(int i=0; i<edges.size(); i++){

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i=0; i<vtx; i++){

        if(!vis[i]){

            vis[i] = 1;

            bfs(i,adj,vis,res);
        }
    }
    
    return res;
}