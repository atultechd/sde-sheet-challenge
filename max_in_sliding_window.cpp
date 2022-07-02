// TC: O(n * k), SC: O(n-k+1);
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> res;
    int n = nums.size();
    for(int i=0; i<=n-k; i++){
        int max = nums[i];
        for(int j=1; j<k; j++){
            if(nums[i+j] > max) max = nums[i+j];
        }
        res.push_back(max);
    }
    return res;
}

// TC: O(n), SC: (k);
#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> res;
    int n = nums.size();
    deque<int> dq;
    int i=0, j=0;
    while(j<n){
        while(dq.size() != 0 && dq.back()< nums[j]){
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            res.push_back(dq.front());
            if(nums[i] == dq.front()) dq.pop_front();
            i++;
            j++;
        }
    }
    return res;
} 