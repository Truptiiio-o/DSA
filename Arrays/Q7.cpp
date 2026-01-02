/*
You are given the head of a doubly Linked List and a key. Your task is to delete all occurrences of the given key and return the new doubly Linked List.

**Example:**

Input: 
2 <-> 2 <-> 10 <-> 8 <-> 4 <-> 2 <-> 5 <-> 2
Key: 2
Output: 
10 <-> 8 <-> 4 <-> 5
*/


ListNode* delete_DLL(ListNode* head, int k){
  ListNode* temp=head;  
  Listnode* back=NULL;
 while(temp!=NULL){ 
  ListNode* front = temp->next;
/* iffff started*/    if(temp->val==k){
      if(temp==head) {
        head=front;
          if(front!=NULL){
            front->prev=NULL;
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
/* else of that iffff*/ else{

  back=temp;
  temp=front;
}
 }
  return head;
}
