void preorder(TreeNode* root){
  if(root==NULL) return;
  cout<<root->val;
  preorder(root->left);
  preorder(root->right);
}

void Inorder(TreeNode* root){
  if(root==NULL) return;
  
  Inorder(root->left);
  cout<<root->val;
  Inorder(root->right);
}

void Postorder(TreeNode* root){
  if(root==NULL) return;
 
  Postorder(root->left);
  Postorder(root->right);
   cout<<root->val;
}
