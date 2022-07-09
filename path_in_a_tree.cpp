/*   
    template <typename T = int>
  class TreeNode
  {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
      this->data = data;
      left = NULL;
      right = NULL;
    }

    ~TreeNode()
    {
      if (left != NULL)
      {
          delete left;
      }
      if (right != NULL)
      {
        delete right;
      }
    }
  };
*/

void tree_traversal(TreeNode<int> *root, int x, vector<int> &path){

    if(root == NULL) return;

    path.push_back(root->data);

    if(root->data == x) return;

    tree_traversal(root->left, x, path);
    tree_traversal(root->right, x, path);

    if(path[path.size()-1] != x) path.pop_back();
}


vector<int> pathInATree(TreeNode<int> *root, int x){

    vector<int> path;

    tree_traversal(root, x, path);

    return path;
}
