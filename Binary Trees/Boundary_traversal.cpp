#include<iostream>
using namespace std;

/*
#####  APPROACH  #####
    ANTICLOCKWISE
1) we first need to have all the left side nodes (left tree )
2) then we need the leaf nodes 
3) then we will add the nodes of the right tree 

1 --> for the left side
                 if left exists then add left to the data structure 
                 else add the right
                 else if when both are null .. we arrived at the leaf node
2 --> for thr leaf node part 
                 to inorder traversal
3 --> start from thetop and make another data structure (STACK)
                 if there exists a right then add a right 
                 else add the left 
                 else we arrived at the leaf node so stop 

*/

void addleft(Node* root,vector<int> &res){
  Node* curr=root->left;
  while(curr){
    if(!isLeaf(curr)) res.push_back(curr->val);// if it is not a leaf then we can add it to our vector
    if(curr->left) curr=curr->left;
    else curr=curr->right;
    
  }
}

void addright(Node*root,vector<int> &res){
  Node*curr=root->right;
  vector<int> temp;
  while(curr){
    if(!isleft(curr)) temp.push_back(curr->val);
    if(curr->right) curr=curr->right;
    else curr=curr->left;
  }
  for(int i=temp.size();i>=0;i--){
    res.push_back(temp[i]);
  }
}


void addleaves(Node* root,vector<int> &res){
  if(isLeaf(root)){
    res.push_back(root->val);
    return;
  }
  if(root->left) addleaves(root->left,res);
  if(root->right) addleaves(root->right,res);
}

//main function 
vector<int> printBoundary(Node* root){
  vector<int> res;
  if(root==NULL) return res;
  if(!ifLeaf(root)) res.push_back(root->data);
  addleft(root,res);
  addleaves(root,res);
  addright(root,res);
  return res;
}

