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
bool solve(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int>*> &st){

    st.push(root);

    if(!root->left && !root->right){

        if(root->data == leaf->data) return true;
        else st.pop(); return false;

    }

    if(root->left){

        if(solve(root->left, leaf, st)) return true;

    }

    if(root->right){

        if(solve(root->right, leaf, st)) return true;

    }

    st.pop();

    return false;
}



TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf){

    if(!root) return NULL;

    stack<TreeNode<int>*> st;

    // bool tou bahana hai main motive tou stack me elements ko daalna hai
    bool b = solve(root, leaf, st);

    // this node always be equal to leaf kyonki last me leaf hi hamara root
    // hone wala hai.
    TreeNode<int>* new_node = st.top();

    st.pop();

    TreeNode<int> *temp = new_node;

    while(!st.empty()){

        auto curr = st.top();
        st.pop();

        if(curr->left == temp){

            curr->left = NULL;
            temp->left = curr;
        }

        else{

            curr->right = curr->left;
            curr->left = NULL;
            temp->left = curr;

        }

        temp = curr;

    }

    return new_node;
}