/*Your task is to implement the function atoi. The function takes a string (str) as an argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt functions.

Example 1:
Input:
str = "123"
Output: 123

Example 2:
Input:
str = "21a"
Output: -1
Explanation: Output is -1 as not all characters are digits.
*/

/*
approach 
first a function that willc onvert string to digits and also a recursive such that it will kepp forming digit by stroing prev also along with it 
we go from back to front of the string 
if it is a negative sring it might consider '-' sign as an invald therefore we check by ourself 
if str[0] = - then we go only till str[1] and add - sign infornt of the ans 
*/


#include<iostream>
#include<vectors>
using namespace std;

int getnum(int i, int start , string &str){
  if(i<start) return 0;

  if(str[i]< '0' || str[i]> '9') return 1e9;

  int digit=str[i] - '0';
  int prev=getnum(i-1;start,str);

  if(prev==1e9) return 1e9;

  return prev*10 + digit;
}

int ATOI(string str){
  int start=0;
  bool isnegative =false;
  int n=str.size();

  if(str[0]== '-') {
    start=1;
    isnegative=true;
  }

  int ans=getnum(n-1,start,str);
  if(ans==1e9) return -1;

 return  isnegative? -ans:ans;

  
}
