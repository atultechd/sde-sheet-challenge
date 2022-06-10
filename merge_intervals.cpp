#include <bits/stdc++.h>
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    int n = intervals.size();
    int idx = 0;
    vector<vector<int>> ans;
    ans.push_back(vector<int>(2));
    sort(intervals.begin(), intervals.end());
    ans[0][0] = intervals[0][0];
    ans[0][1] = intervals[0][1];
    for(int i=1; i<n; i++){
        if(ans[idx][1] >= intervals[i][1]) continue;
        else if(intervals[i][0] <= ans[idx][1]){
            ans[idx][1] = intervals[i][1];
            continue;
        }
        idx++;
        ans.push_back(vector<int>(2));
        ans[idx][0] = intervals[i][0];
        ans[idx][1] = intervals[i][1];
    }
    return ans;
}
