class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


int sum(Node* root){
if(root==NULL) return 0;
return (root->val + sum(root->left)+ sum(root->right));
}

int maxNode(Node* root){
  if(root==NULL) return INT_MIN;
  return max(root->val,max(maxNode(root->left),maxNode(root->right)));
}

int main(){
  Node* a=new Node(2);
  Node* b=new Node(3);
  Node* c=new Node(4);
  Node* d=new Node(5);
  Node* e=new Node(6);
  Node* f=new Node(7);
  a->left=b;
  a->right=c;
  b->left=d;
  b->right=e;
  c->left=f;
  cout<<sum(a);
  cout<<maxNode(a);
  
}

