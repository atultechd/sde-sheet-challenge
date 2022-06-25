#include<bits/stdc++.h>

bool is_possible(vector<int> positions , int n ,  int c, int gap){

    int recent = 0, player_placed = 1;

    for(int i=1; i<n; i++){

        if(positions[i] - positions[recent] >= gap){
            player_placed ++, recent = i;
        }
    }

    return (player_placed >= c) ? true : false;
}

int chessTournament(vector<int> positions , int n ,  int c){

    sort(positions.begin(), positions.end());
    
    int low=0;
    int high=positions[n-1]-positions[0];
    int ans=0;

    while(low <= high){

        int mid =(low+high)/2;

        if(is_possible(positions,n,c,mid)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}