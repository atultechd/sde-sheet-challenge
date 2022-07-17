#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){

    vector<int> res;

    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    s.push(arr[0]);

    res.push_back(s.top());

    for(int i=1; i<n; i++){

        int x=arr[i];

        if(s.size() > g.size()){

            if(s.top() > x){

                g.push(s.top());
                s.pop();
                s.push(x);
            }

            else g.push(x);
            
            res.push_back((g.top()+s.top())/2);
        }

        else{

            if(s.top() >= x) s.push(x);

            else{

                g.push(x);
                s.push(g.top());
                g.pop();

            }

            res.push_back(s.top());
        }
    }
    
    return res;
}
