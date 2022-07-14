/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x){

    int floor =0;

    while(root){

        if(root->val == x) return root->val;

        else if(root->val > x){

            root = root->left;

        }

        else if(root->val < x){

            floor = root->val;
            root = root->right;
        }
    }
    
    return floor;
}