
#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> stk;
    vector<int> res;
    for(int i=arr.size()-1; i>=0; --i){
        if(stk.empty()) res.push_back(-1);
        else{
            while(!stk.empty() && stk.top() <= arr[i]){
                stk.pop();  
            }
            if(stk.empty()) res.push_back(-1);
            else res.push_back(stk.top());
        }
        stk.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;

}