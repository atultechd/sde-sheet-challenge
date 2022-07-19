#include<bits/stdc++.h>

void topo_sort(int node, vector<bool> &vis, stack<int> &s, unordered_map<int,list<int>> &adj){

    vis[node] = 1;

    for(auto neighbour: adj[node]){

        if(!vis[neighbour]){

            topo_sort(neighbour, vis, s, adj);

        }
    }
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int,list<int>> adj;

    for(int i=0; i<e; i++){

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> vis(v);

    stack<int> s;

    for(int i=0; i<v; i++){

        if(!vis[i]){

            topo_sort(i,vis,s,adj);
        }
    }

    vector<int> res;

    while(!s.empty()){

        res.push_back(s.top());

        s.pop();
    }
    
    return res;
}