//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

bool check(TreeNode* p,TreeNode* q){
  if(p==NULL && q==NULL) return true;
  if(p==NULL || q==NULL) return false;

  if(p->val!=q->val) return NULL;
  check(p->left,q->right);
  check(p->right,q->left);
}


bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return check(root->left, root->right);
    }


/*
basically see leetcode 101
here the base conditions are obv and we will take 2 parameters for function check
then their value should be equal 
if it is the check for the values of p's right and q's left 
and then check for the values of p's left and q's right
*/
