#include<bits/stdc++.h>

// TC: O(nlogn), SC: O(1);
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
  vector<int> res(2);
  sort(arr.begin(), arr.end());
  res.push_back(arr[k-1]);
  res.push_back(arr[arr.size()-k]);
  return res;
}


// TC: O(nlogK), SC: O(n);
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
  priority_queue<int> maxh;
  priority_queue<int, vector<int>, greater<int>> minh;
  vector<int> res(2);
  
  for(int i=0; i<n; i++){
      maxh.push(arr[i]);
      minh.push(arr[i]);
      if(maxh.size()>k){
          maxh.pop();
          minh.pop();
      }
  }
  res[0] = maxh.top();
  res[1] = minh.top();
  return res;
}