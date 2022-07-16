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
void convert_bt_to_dll(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev){

    if(!root) return;

    convert_bt_to_dll(root->left, head, prev);

    if(prev == NULL) head = root;

    else{

        root->left = prev;
        prev->right = root;

    }

    prev = root;

    convert_bt_to_dll(root->right, head, prev);
}

    
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {

    BinaryTreeNode<int> *head = NULL, *prev = NULL;

    convert_bt_to_dll(root,head,prev);
    
    return head;
}