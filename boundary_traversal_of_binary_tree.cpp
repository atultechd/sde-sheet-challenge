/************************************************************

    Following is the Binary Tree node structure:
    
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
void left_tree(TreeNode<int>* root, vector<int> &res){
    if(!root) return;
    if(root->left){
        res.push_back(root->data);
        left_tree(root->left, res);
    }
    else if(root->right){
        res.push_back(root->data);
        left_tree(root->right,res);
    }
}

void right_tree(TreeNode<int>* root, vector<int> &res){
    if(!root) return;
    if(root->right){
        right_tree(root->right, res);
        res.push_back(root->data);
    }
    else if(root->left){
        right_tree(root->left,res);
        res.push_back(root->data);
    }
}

void leaf(TreeNode<int>* root, vector<int> &res){
    if(!root) return;
    leaf(root->left, res);
    if(!root->left && !root->right){
        res.push_back(root->data);
    }
    leaf(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    res.push_back(root->data);
    if(!root->left && !root->right) return res;
    left_tree(root->left, res);
    leaf(root, res);
    right_tree(root->right, res);
    return res;
}