/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

*/


#include<iostream>
using namespace std;

bool rotated(int a[]){
  int drop=0;
  for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
      drop++;
    }
    if(a[0]<a[n-1]) drop++;
    
  }
if(drop>1) return false;
  else return true;
  
}
