ListNode* delete_DLL(ListNode* head, int k){
  ListNode* temp=head;  
  Listnode* back=NULL;
 while(temp!=NULL){ 
  ListNode* front = temp->next;
    if(temp->val==k){
      
      
      if(temp==head) {
      head=front;
        if(head!=NULL){
          head->prev=NULL;
        }
      }
      else{      
      back->next=front;
      if (front != NULL) {
        front->prev = back;
           }
      
     }
      delete temp;
      temp=front;
  
}
else{

  back=temp;
  temp=front;
}
 }
  return head;
}
