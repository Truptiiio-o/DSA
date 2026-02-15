
//Given the root of a binary tree, invert the tree, and return its root.


#include<iostream>

void helper(Node* root){
  if(root==NULL) return;
  Node* temp=root->left;
  root->left=root->right;
  root->right=temp;
  helper(root->left);
  helper(root->right);
}

Node* InvertBT(Node* root){
  helper(root);
  return root;
}
