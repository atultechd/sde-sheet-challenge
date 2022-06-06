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
bool validate_left(BinaryTreeNode<int>* , int);
bool validate_right(BinaryTreeNode<int>*, int);


bool validate_left(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) return true;  
    if(root -> data > data) return false;
    return (validate_left(root -> left, root -> data) && validate_right(root -> right, root -> data));
}

bool validate_right(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) return true;  
    if(root -> data < data) return false;
    return (validate_left(root -> left, root -> data) && validate_right(root -> right, root -> data));
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(root == NULL) return true;
    return (validate_left(root -> left, root -> data) && validate_right(root -> right, root -> data));
}