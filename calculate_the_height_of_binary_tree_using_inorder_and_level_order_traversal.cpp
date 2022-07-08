#include<bits/stdc++.h>
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){

    unordered_map<int,int> m;

    queue<vector<int>> q;

    for(int i=0; i<inorder.size(); i++){

        m[inorder[i]] = i;
    }

    if(m.find(levelOrder[0]) != m.end()){

        if(m[levelOrder[0]] == inorder.size()-1){
            q.push({0,(int)inorder.size()-2, 1});
        }
        else if(m[levelOrder[0]] == 0){
            q.push({1,(int)inorder.size()-1, 1});
        }
        else{
            q.push({0,m[levelOrder[0]]-1,1});
            q.push({m[levelOrder[0]]+1, (int)inorder.size()-1, 1});
        }
    }

    int k = 1;

    int ans = 0;

    while(!q.empty()){

        auto temp = q.front();

        q.pop();

        ans = max(ans, temp[2]);

        if(m.find(levelOrder[k]) != m.end()){

            if(temp[0] == temp[1]){
                ans = max(ans, temp[2]+1);
            }

            else if(m[levelOrder[k]] == temp[1]){
                q.push({temp[0], temp[1]-1, temp[2]+1});
            }

            else if(m[levelOrder[k]] == temp[0]){
                q.push({temp[0]+1, temp[1], temp[2]+1});
            }

            else{
                q.push({temp[0], m[levelOrder[k]]-1, temp[2]+1});
                q.push({m[levelOrder[k]]+1 ,temp[1], temp[2]+1});
            }
        }

        k++;
    }
    
    return ans-1;
}






