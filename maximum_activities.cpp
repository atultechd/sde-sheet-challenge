#include<bits/stdc++.h>
struct max_activities{
        int start;
        int end;
};
bool cmp(struct max_activities m1,max_activities m2){
    return m1.end< m2.end;
}

int maximumActivities(vector<int> &s, vector<int> &e) {
    int n = s.size();
    struct max_activities job[n];
    for(int i=0; i<n; i++){
        job[i].start = s[i], job[i].end = e[i];
    }
    sort(job, job+n, cmp);
    int res =1;
    int ending = job[0].end;
    for(int i=1; i<n; i++){
        if(job[i].start >= ending){
            ending = job[i].end;
            res++;
        }
    }
    return res;
}