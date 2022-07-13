#include<bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {

    if(!root) return;

    queue<BinaryTreeNode<int>*> que;

    que.push(root);

    while(!que.empty()){

        int sizee = que.size();

        for(int i=1; i<=sizee; i++){

            BinaryTreeNode< int > *temp = que.front();

            que.pop();

            if(i < sizee) temp->next = que.front();

            if(temp->left) que.push(temp->left);

            if(temp->right) que.push(temp->right);
            
        }
    }
}