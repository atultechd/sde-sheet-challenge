#include<bits/stdc++.h>

// dfs use karne ka main motive stack me elements store karna(topological_sort)
void dfs(int node, unordered_map<int,bool> &vis, stack<int> &st, unordered_map<int,list<int>> &adj){

    vis[node] = true;

    for(auto neighbour: adj[node]){

        if(!vis[neighbour]){

            dfs(neighbour, vis, st, adj);
        }
    }

    st.push(node);
}


// rev_dfs use karne ka main motive jo already stack me hoga usse hi consider karna hai.
void rev_dfs(int node, unordered_map<int,bool> &vis, unordered_map<int,list<int>> &transpose, vector<int> &res){

    vis[node] = true;

    res.push_back(node);

    for(auto neighbour: transpose[node]){

        if(!vis[neighbour]){

            rev_dfs(neighbour, vis, transpose, res);
        }
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){

    vector<vector<int>> ans;

    unordered_map<int,list<int>> adj;

    for(int i=0; i<edges.size(); i++){

        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    stack<int> st;

    unordered_map<int,bool> vis;

    for(int i=0; i<n; i++){

        if(!vis[i]){

            dfs(i,vis,st,adj);
        }
    }
    
    unordered_map<int,list<int>> transpose;

    for(int i=0; i<n; i++){

        vis[i] = false;

        for(auto nbr: adj[i]){

            transpose[nbr].push_back(i);
        }
    }

    int count = 0;

    while(!st.empty()){

        int top = st.top();

        st.pop();

        if(!vis[top]){

            vector<int>res;

            rev_dfs(top,vis,transpose,res);

            ans.push_back(res);
        }
    }
    
    return ans;
}