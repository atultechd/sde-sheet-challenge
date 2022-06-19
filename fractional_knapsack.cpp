
#include<bits/stdc++.h>
bool cmp(pair<int,int> a, pair<int,int> b){
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;
    return r1>r2;    
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), cmp);
    int cur_weight = 0;
    double final_val = 0.0;
    
    for(int i=0; i<n; i++){
        if(cur_weight + items[i].first <= w){
            cur_weight += items[i].first;
            final_val += items[i].second;
        }
        else{
            int remain = w - cur_weight;
            final_val +=((double)items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    return final_val;
}