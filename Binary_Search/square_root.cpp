/*
QUESTION:
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example:

Input:
x = 5
Output: 2*/

// ******APPROACH **********
// simple binary search approach which is verty rare to think but once u see it very very simple and staright forward code 
// TC -O(n)   and SC = O(1)


int root(int n){
  int low=1;
  int high=n;
  while(low<=high){
    long long mid=low+(high-low)/2;
    if(mid*mid==n) return mid;
    else if(mid*mid<n){
      low=mid+1;
  }
    else high=mid-1;
}
return high;
}
