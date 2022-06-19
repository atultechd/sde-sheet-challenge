#include<bits/stdc++.h>
struct format{
    int deadline;
    int profit;
};
bool cmp(struct format a, format b){
    return a.profit > b.profit;
}

int jobScheduling(vector<vector<int>> &jobs){
    int n=jobs.size();
    struct format job[n];
    for(int i=0; i<n; i++){
        job[i].deadline = jobs[i][0];
        job[i].profit = jobs[i][1];
    }
    sort(job, job+n, cmp);
    int max_deadline = 0;
    for(int i=0; i<n; i++){
        max_deadline = max(max_deadline, job[i].deadline);
    }
    vector<int> filled(max_deadline+1, -1);
    int max_profit = 0;
    for(int i=0; i<n; i++){
        for(int j= job[i].deadline; j>0; j--){
            if(filled[j] == -1){
                filled[j] = 0;
                max_profit += job[i].profit;
                break;
            }
        }
    }
    return max_profit;
}
