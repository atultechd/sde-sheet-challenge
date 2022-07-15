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

class BSTiterator{

private: stack<TreeNode<int>*> s;

public:

    BSTiterator(TreeNode<int> *root){

        pushall(root);
    }
    
    bool hasNext(){

        return !s.empty();
    }

    int next(){

        TreeNode<int> *temp = s.top();

        s.pop();

        pushall(temp->right);

        return temp->data;
    }

private:

    void pushall(TreeNode<int> *root){

        for(; root != NULL; s.push(root), root = root->left);
          
    }
    
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/