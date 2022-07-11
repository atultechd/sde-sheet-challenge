#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *makeBT(vector<int>&preorder, int pre_start, int pre_end, vector<int>&inorder, int in_start, int in_end, map<int,int> &m){

    if(pre_start > pre_end || in_start > in_end) return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[pre_start]);

    int in_root = m[root->data];

    int nums_left = in_root - in_start;
    
    root->left = makeBT(preorder, pre_start+1, pre_start+nums_left, inorder, in_start, in_root-1, m);

    root->right = makeBT(preorder, pre_start+nums_left+1, pre_end, inorder, in_root+1, in_end, m);

    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){

    map<int,int> m;

    for(int i = 0; i< inorder.size(); i++){

        m[inorder[i]] = i;

    }

    TreeNode<int> *root =  makeBT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
    
    return root;
}