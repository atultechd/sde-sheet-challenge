/************************************************************
    Following is the Binary Search Tree node structure
    
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

void inOrder(TreeNode<int> *root, vector<int> &inorder){

    if(!root) return;

    inOrder(root->left, inorder);

    inorder.push_back(root->data);

    inOrder(root->right, inorder);
}

int KthLargestNumber(TreeNode<int>* root, int k) {

    vector<int> inorder;

    inOrder(root, inorder);

    for(int i=0; i<inorder.size(); i++){

        if(i == inorder.size()-k) return inorder[i];

    }

    return -1;
}




// another way of doing this problem
int KthLargestNumber(TreeNode<int>* root, int k) { 

    stack<TreeNode<int>*> s;

    while(root || !s.empty()){

        while(root){

            s.push(root);
            root = root->right;

        }

        root = s.top();

        s.pop();

        if(--k == 0) break;

        root = root->left;
    }

    return root==NULL ? -1 : root->data;
}
