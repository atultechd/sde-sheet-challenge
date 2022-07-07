#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void get_inorder(BinaryTreeNode<int> *root, vector<int> &res1){

    if(root==NULL) return;

    get_inorder(root->left, res1);

    res1.push_back(root->data);

    get_inorder(root->right, res1);
    
}

void get_preorder(BinaryTreeNode<int> *root, vector<int> &res2){

    if(root==NULL) return;

    res2.push_back(root->data);

    get_preorder(root->left, res2);

    get_preorder(root->right, res2);
    
}

void get_postorder(BinaryTreeNode<int> *root, vector<int> &res3){

    if(root==NULL) return ;

    get_postorder(root->left, res3);

    get_postorder(root->right, res3);

    res3.push_back(root->data);
    
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<vector<int>> ans;

    vector<int> res1;
    vector<int> res2;
    vector<int> res3;

    get_inorder(root, res1);
    ans.push_back(res1);

    get_preorder(root, res2);
    ans.push_back(res2);

    get_postorder(root, res3);
    ans.push_back(res3);
    
    return ans;
}


// ...........................................................................


// merge all three functions in one.
// smaller code than above.

void get_in_pre_post(BinaryTreeNode<int> *root, vector<int> &res1, vector<int> &res2, vector<int> &res3){

    if(root==NULL) return;

    res2.push_back(root->data);

    get_in_pre_post(root->left, res1, res2, res3);

    res1.push_back(root->data);

    get_in_pre_post(root->right, res1, res2, res3);

    res3.push_back(root->data);
    
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<int> res1, res2, res3;

    get_in_pre_post(root, res1, res2, res3);

    return {res1, res2, res3};
}

