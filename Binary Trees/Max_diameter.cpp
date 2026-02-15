/*Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

 */

// APPROACH
// int this basicaly the longest diameter may not always be the one passing through the root node 
// therefore we did not do height of lft subtree +right subtree +1;
// it can be something that is not passing through the root node
int dia=0;


int height(Node* root){
  if(root==NULL) return 0;

  // Step 1: get heights of left & right subtrees
  int lh=height(root->left);
  int rh=height(root->right);

  // Step 2: update diameter at this node
    // longest path passing through this node
  int dia=max(dia,lh+rh);
   // Step 3: return height of current node
    // height = 1 + max(left, right)
  return 1+max(lh+rh);
}

int DiameterOfBinaryTree(Node* root){
  height(root);
  return dia;
  
}
