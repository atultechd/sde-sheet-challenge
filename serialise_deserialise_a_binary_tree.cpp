#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root){
//     For serializing the tree
//     We'll use level order traversal.
    if(!root) return "";

    string s = "";

    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode<int> *temp = q.front();

        q.pop();

        if(temp == NULL) s.append("#,");

        else s.append(to_string(temp->data)+',');

        if(temp){

            q.push(temp->left);
            q.push(temp->right);

        }

    }

    return s;

}

TreeNode<int>* deserializeTree(string &data){

    if(data.size() == 0) return NULL;

    stringstream s(data);

    string str;

    getline(s,str,',');

    TreeNode<int> *root = new TreeNode<int>(stoi(str));

    queue<TreeNode<int> *> q;

    q.push(root);

    while(!q.empty()){

        TreeNode<int> *node = q.front();

        q.pop();

        getline(s,str,',');

        if(str == "#") node->left = NULL;

        else{

            TreeNode<int> *left_node = new TreeNode<int>(stoi(str));
            node->left = left_node;
            q.push(left_node);
        }
        
        getline(s,str,',');

        if(str == "#") node->right = NULL;

        else{

            TreeNode<int> *right_node = new TreeNode<int>(stoi(str));
            node->right = right_node;
            q.push(right_node);
        }
    }
    return root;
}