#include<bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> res;

    if(root==NULL) return res;

    queue<pair<TreeNode<int>*, pair<int,int>>> q;

    map<int,map<int,vector<int>>> m;

    q.push({root, {0,0}});

    while(!q.empty()){

        TreeNode<int> *temp = q.front().first;

        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        m[x][y].push_back(temp->data);

        if(temp->left != NULL) q.push({temp->left, {x-1,y+1}});

        if(temp->right != NULL) q.push({temp->right, {x+1,y+1}});
    }

    vector<vector<int>> ans;

    for(auto i : m){
        vector<int> col;
    
        for(auto p : i.second){
    
            col.insert(col.end(), p.second.begin(), p.second.end());
        }

        ans.push_back(col);        
    }

    for(auto i : ans){

        for(auto p : i){
            res.push_back(p);
        }
    }
    
    return res;
}









