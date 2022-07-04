#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    if(grid.empty())return 0;

    int total = 0, days = 0, count = 0;

    queue<pair<int,int>> rotten;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 0) total++;
            if(grid[i][j] == 2) rotten.push({i,j});
        }
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(!rotten.empty()){
        int k = rotten.size();
        count += k;

        while(k--){
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dx[i], new_y = y + dy[i];
                if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || grid[new_x][new_y] != 1) continue;
                grid[new_x][new_y] = 2;
                rotten.push({new_x, new_y});
            }
        }

        if(!rotten.empty())days++;
    }
    
    return total == count ? days : -1;
}