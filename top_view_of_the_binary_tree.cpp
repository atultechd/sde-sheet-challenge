#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {

    vector<int> res;

    if(root==NULL) return res;

    queue<pair<TreeNode<int>*, int>> q;
    map<int,int> m;

    q.push({root,0});

    while(!q.empty()){

        TreeNode<int> *temp = q.front().first;
        int dist = q.front().second;

        q.pop();

        if(m.count(dist)==0) m[dist] = temp->val;

        if(temp->left != NULL) q.push({temp->left,dist-1});

        if(temp->right != NULL) q.push({temp->right,dist+1});
    }

    for(auto i: m) 
        res.push_back(i.second);
      
    return res;
}





