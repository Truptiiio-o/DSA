/*Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.*/

#include<iostream>
using namespace std;

void helper(TreeNode* root, vector<string> &ans, string curr){
  if(root==NULL) return;
  curr+=to_string(root->val);
  if(root->left==NULL && root->right==NULL){
    ans.push_back(curr);
    return;
  }
  curr+="->";
  helper(root->left,ans,curr);
  helper(root->right,ans,curr);
}
