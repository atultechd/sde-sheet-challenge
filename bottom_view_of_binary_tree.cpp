#include<bits/stdc++.h>
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> res;

    if(root==NULL) return res;

    queue<pair<BinaryTreeNode<int>*, int>> q;
    map<int,int> m;

    q.push({root,0});

    while(!q.empty()){

        BinaryTreeNode<int> *temp = q.front().first;
        int dist = q.front().second;

        q.pop();

        m[dist] = temp->data;

        if(temp->left != NULL) q.push({temp->left,dist-1});

        if(temp->right != NULL) q.push({temp->right,dist+1});

    }

    for(auto i: m) 
        res.push_back(i.second);
      
    return res;
}






