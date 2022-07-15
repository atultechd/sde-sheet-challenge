/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class info{
public:
    int maxi;
    int mini;
    bool is_bst;
    int size;
};

info solve(TreeNode<int> *root, int &ans){

    if(!root) return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
     
    info curr_node;
    curr_node.size = left.size + right.size + 1;
    curr_node.maxi = max(root->data, right.maxi);
    curr_node.mini = min(root->data, left.mini);
    
    if(left.is_bst && right.is_bst && (root->data > left.maxi && root->data < right.mini)) curr_node.is_bst = true;

    else curr_node.is_bst = false;
    
    if(curr_node.is_bst)

        ans = max(ans,curr_node.size);
    
    return curr_node;
}

int largestBST(TreeNode<int>* root) {

    int maxsize = 0;

    info temp = solve(root, maxsize);
    
    return maxsize;
}
