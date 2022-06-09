#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int maxof = 0, minof = prices[0];
    for(int i=0; i<prices.size(); i++){
        minof = min(minof, prices[i]);
        maxof = max(maxof, prices[i] - minof);
    }
    return maxof;
}