#include<bits/stdc++.h>
vector<int> next_smaller_right_index(vector<int>&arr){
    vector<int> res;
    stack<pair<int,int>> s;
    for(int i=arr.size()-1; i>=0; i--){
        if(s.empty()) res.push_back(arr.size());
        else{
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()) res.push_back(arr.size());
            else res.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> next_smaller_left_index(vector<int>&arr){
    vector<int> res;
    stack<pair<int,int>> s;
    for(int i=0; i<arr.size(); i++){
        if(s.empty()) res.push_back(-1);
        else{
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()) res.push_back(-1);
            else res.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    return res;
}

int largestRectangle(vector<int> & arr) {
//     ns_right -> next_smaller_right
    vector<int> ns_right = next_smaller_right_index(arr);
    
//     ns_left -> next_smaller_left
    vector<int> ns_left = next_smaller_left_index(arr);   

    vector<int> width;

    int maxi = INT_MIN;
    
    for(int i=0; i<arr.size(); i++){
        width.push_back(ns_right[i] - ns_left[i] -1);
        maxi = max(maxi, (arr[i] * width[i]));
    }
    return maxi;
}