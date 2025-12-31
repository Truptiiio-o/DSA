
ListNode* getKthNode(ListNode* temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;}

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL) return head;

    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        ListNode* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}

 ListNode* reverseKGroup(ListNode* head, int k) {
   ListNode* temp=head;
   ListNode* prevNode=NULL;
   while(temp!=NULL){
     ListNode* KthNode =getKthNode(temp,k);
     if(KthNode==NULL){
       if(prevNode) prevNode->next=temp;
       break;
     }
     ListNode* nextNode=KthNode->next;
     KthNode->next=NULL;
     reverse(temp);
     if(temp==head) head=KthNode;
     else{
       prevNode->next=KthNode;
     }
     prevNode=temp;
     temp=nextNode;
   }
   return head;

   
 }
