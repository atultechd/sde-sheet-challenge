#include<bits/stdc++.h>

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode *root, vector<int> &res){
    if(root == NULL)return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}