/*QUESTION 13:
Reverse a given stack of 'N' integers using recursion.
Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.

Example:
Input: [1,2,3,4,5]
Output: [5,4,3,2,1]

/*Remove the top element
Reverse the remaining stack
Insert the removed element at the bottom*/

/* The 'insertAtBottom' function inserts the given element at the bottom of the stack using recursion.
   If the stack is empty, push the element to the stack and return.
   Otherwise, pop the top element from the stack and recursively call 'insertAtBottom' with the element and the modified stack.
     After the recursive call, push the popped element back to the stack.
Create the main function called 'reverseStack' that reverses the given stack using recursion.
   Base case: If the stack is empty, return.
   Otherwise, pop the top element from the stack and recursively call 'reverseStack' on the modified stack.
     After the recursive call, call the 'insertAtBottom' function with the popped element and the modified stack.
*/


#include<iostream>
using namespace std;


void insertAtBottom(stack<int> &str, int e){
  if(str.empty){
    stack.push(e);
    return;}

  int temp=str.top();
  str.pop();
  insertAtBottom(str,e);
  str.push(temp);

    
}

void reverseStack(stack<int> &str){
  if(str.empty) return;

  int top=str.top();
  str.pop();
  reverseStack(str);
  insertAtBottom(str,top);
  
}
