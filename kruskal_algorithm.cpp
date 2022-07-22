#include<bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findparent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findparent(parent, u);
    v = findparent(parent, v);
    
    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[v] < rank[u]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
  
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(), graph.end(), cmp);
  vector<int> parent(n+1);
    vector<int> rank(n);
    makeset(parent,rank,n);
    int min_weight = 0;
    for(int i=0; i<graph.size(); i++){
        int u = findparent(parent,graph[i][0]);
        int v = findparent(parent,graph[i][1]);
        int w = graph[i][2];
        if(u != v){
            min_weight += w;
            unionset(u,v,parent,rank);
        }
    }
    return min_weight;
}