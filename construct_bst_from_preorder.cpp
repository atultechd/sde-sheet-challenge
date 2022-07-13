#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
// naive solution TC: O(nlogn);
TreeNode<int>* construct_bst(vector<int> &arr, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end-start) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = construct_bst(arr, start, mid-1);
    root->right = construct_bst(arr, mid+1, end);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    sort(preOrder.begin(), preOrder.end());
    int n = preOrder.size();
    if(n==0)return NULL;
    return construct_bst(preOrder, 0, n-1);
}


// optimised solution TC: O(n);
TreeNode<int>* build_bst(vector<int> &preOrder, int &ind, int upper_bound){
    if(ind == preOrder.size() || preOrder[ind] > upper_bound) return NULL;
    TreeNode<int>* root = new TreeNode<int>(preOrder[ind++]);
    root->left = build_bst(preOrder, ind, root->data);
    root->right = build_bst(preOrder, ind, upper_bound);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
    return build_bst(preOrder, i, 1e9+1);
}