/*
QUESTION:-
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75*/

 ListNode* reverseDLL(ListNode* head){
   ListNode* back=NULL;
   ListNode* curr=head;
   while(curr!=NULL){
     ListNode* front=curr->next;
     curr->next=back;
     curr->prev=front;
     back=curr;
     curr=front;
   }
   return back;
 }
