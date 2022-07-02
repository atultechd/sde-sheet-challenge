#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;

    if(root==NULL) return res;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    // it works as flag; 
    int pos = 1;

    while(!q.empty()){

        int size = q.size();
        vector<int> temp;

        for(int i=0; i<size; i++){
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            temp.push_back(front->data);
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
        // for storing data in zigzag form we use pos variable
        if(pos%2==0)
            reverse(temp.begin(), temp.end());

        for(int i=0; i<size; i++)
            res.push_back(temp[i]);

        // switch pos from (0 to 1) or (1 to 0) 
        pos = !pos;
    }
    
    return res;
}
