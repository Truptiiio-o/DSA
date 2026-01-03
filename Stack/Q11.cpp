/*QUESTION 10:
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:
Input:
Stack: 3 2 1
Output: 3 2 1

Example 2:
Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2

//approach
/*
basically first we start with the sortstack function which will empty the stack completly with its recurrsive calls then 
we insert the last popped elmemt by backtracking 
and now again insert function is called for previous ka previos popped element if that element is > the element already present in that stack then okay and push it into the stack 
otherwise pop uske previous vala check the x>=top condition again until this gets saisfied and hanece insert the element at the right palce 
similarly again the next insert function is called through sortstack and sooo on 



  */

#include<iostream>
using namespace std;

void insert(stack<int> &st , int x){
  if(st.empty() || st.top <=x) // most useful condition since we can the sorted array with greater elemts at the top 
  {st.push(x);
  return;}

  int temp=st.top();
  st.pop();
  insert(st,x); // if the above condition not gets satisfied pop one elemnt and check until it gets satisfied 
  //creating another recurrsive call loop
  st.push(temp);

  
} 

void sortStack(stack<int> &st){
  if(st.empty()) return;

  int top=st.top();
  st.pop();

  sortStack(st); /// till the stack is completly empty 
  insert(st,top); // starts after the stack becomes empty and one by one the elemnts are thrown into it by backtrackig 
}
