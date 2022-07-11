#define lli long long int
/************************************************************

    Following is the Tree node structure
  
  template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
lli solve(TreeNode<int> *root, lli &res){
    if(!root) return 0;
    lli left = solve(root->left, res);
    lli right = solve(root->right, res);
    res = max(res, (left + right + root->val));
    return max(left, right)+ root->val;
}

lli findMaxSumPath(TreeNode<int> *root){
    if(!root) return -1;
    if(!root->left || !root->right) return -1;
    lli res = 0;
    solve(root, res);
    return res;
}


