#include<bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool helper(BinaryTreeNode<int> *root, unordered_set<int> &s, int k){

    if(!root) return false;

    if(s.find(k-root->data) != s.end())return true;

    s.insert(root->data);

    return helper(root->left, s, k) || helper(root->right, s, k);

}

bool pairSumBst(BinaryTreeNode<int> *root, int k){

    unordered_set<int> s;
    
    return helper(root, s, k);
}