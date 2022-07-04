#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    stack<int> stk;
    vector<int> res(price.size(), 1);
    for(int i=0; i<price.size(); i++){
        int count = 1;
        while(!stk.empty() && price[i] >= price[stk.top()]){
            count += res[stk.top()];
            stk.pop();
        }
        stk.push(i);
        res[i] = count;
    }
    return res;
}