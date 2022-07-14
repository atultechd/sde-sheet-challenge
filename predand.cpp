void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& inorder){
   if(root == NULL){
       return;
   }
   inorderTraversal(root -> left, inorder);
   inorder.push_back(root -> data);
   inorderTraversal(root -> right, inorder);
   return;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
   vector<int> inorder;
   inorderTraversal(root, inorder);
   pair<int,int> ans = make_pair(-1,-1);
   for(int i =0; i< inorder.size(); i++){
       if(inorder[i] == key){
           if(i >=1){
               ans.first = inorder[i-1];
           }
           if(i < inorder.size() -1){
               ans.second = inorder[i+1];
           }
           return ans;
       }
   }
}