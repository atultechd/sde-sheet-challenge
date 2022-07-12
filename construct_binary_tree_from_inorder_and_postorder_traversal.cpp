#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
      { 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
void create_mapping(vector<int> &inOrder, map<int,int> &node_to_index){

    int n = inOrder.size();

    for(int i=0; i<n; i++){

        node_to_index[inOrder[i]] = i;
    }
}

TreeNode<int> *solve(vector<int>& postOrder, int &index, vector<int> &inOrder, int in_start, int in_end, map<int,int> &node_to_index){

    if(index < 0 || in_start > in_end) return NULL;

    int element = postOrder[index--];

    TreeNode<int> *root = new TreeNode<int>(element);

    int position = node_to_index[element];
    
    root->right = solve(postOrder, index, inOrder, position+1, in_end, node_to_index);
    root->left = solve(postOrder, index, inOrder, in_start, position-1, node_to_index);
    
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {

    int post_index = postOrder.size()-1;

    map<int,int> node_to_index;

    create_mapping(inOrder, node_to_index);

    TreeNode<int> *root = solve(postOrder, post_index, inOrder, 0, inOrder.size()-1, node_to_index);





    
    return root;
}












