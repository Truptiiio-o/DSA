/*
QUESTION:-
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.*/

//APPROACH
//slow and fast pointer approach 
// such that till the fast reaches the end 
// slow will be standing on the middle of odd and seond middle of even 

Node* middle(Node*head){
  Node* slow=head;
  Node* fast=head;
  while(fast->next!=NULL && fast!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}

//TC=O(n)
  //SC=O(1)
