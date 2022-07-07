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
int height(TreeNode<int> *root){

    if(root == NULL)return 0;
    
    return 1+ max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(TreeNode<int> *root){

    if(root == NULL)return 0;

    int dl = diameterOfBinaryTree(root->left);

    int dr = diameterOfBinaryTree(root->right);

    int cur = height(root->left) + height(root->right);

    return max(cur, max(dl,dr));
}
