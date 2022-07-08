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

int getMaxWidth(TreeNode<int> *root){

    if(root==NULL)return 0;

    vector<vector<TreeNode<int> *>> res;

    queue<TreeNode<int>*>q;

    q.push(root);

    while(!q.empty()){

        vector<TreeNode<int>*> temp;

        while(!q.empty()){

            temp.push_back(q.front());
            q.pop();
        }

        res.push_back(temp);

        for(int i=0; i<temp.size(); i++){

            TreeNode<int>* node = temp[i];

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }

    int max_width = 0;

    for(int i=0; i<res.size(); i++){

        if(max_width < res[i].size()) max_width = res[i].size();

    }
    
    return max_width;
}