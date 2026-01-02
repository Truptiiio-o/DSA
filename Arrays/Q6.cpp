/*QUESTION 6
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
*/


//approach 
//take  atemp variable at head , find the kth node from there by traversal 
//then store the node next to kth node and break its link such that we get a linked list of knodes 
//thenn use a reverse function on this linked list and if temp==head then after reversal store the new head or update the head 
// after that store the prev node which will be the temp (beacuse temp was the 1st node in k node linked list but after reversal it became the last that is the node prev to next k node linked list)
// after that reverse the next k node linked list in the same way and then if temp!=head connect the prev node to kthnode (because that become the first node of next k node linked after perdorming reversal)
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
