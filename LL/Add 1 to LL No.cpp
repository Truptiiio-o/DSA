
helper(Node* temp){
  if(temp==NULL) return 1;

  carry=helper(temp->next);
  temp->data=temp->data+carry;
  if(temp->data<10) return 0;

  temp->data=0;
  return 1;
}

// for dry run refer
// https://www.youtube.com/watch?v=aXQWhbvT3w0
// at 21.15

function(Node* head){
  carry=helper(head);
  if(carry==1){
    newnode=new Node(1);
    newnode->next=head;
    return newnode;
  }
  return head;
    
}
