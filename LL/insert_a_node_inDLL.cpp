/*
QUESTION:-
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Example 1:

Input:
LinkedList: 2<->4<->5
p = 2, x = 6 
Output: 2 4 5 6
Explanation: p = 2, and x = 6. So, 6 is
inserted after p, i.e, at position 3
(0-based indexing).*/

 ListNode* AddNode(ListNode* head,int p,int x){
   int count=0;
   ListNode* temp=head;
   while(count<p){
     temp=temp->next;
     count++;
       
   }
   ListNode* newnode = new ListNode(x);

   newnode->next=temp->next;
   temp->next=newnode;
   newnode->prev=temp;
   if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

   return head;
   
 }
