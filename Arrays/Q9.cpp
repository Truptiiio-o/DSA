/*Given a list arr of N integers, print the sums of all subsets in it.

Example:
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no element is taken, the sum is 0.
When only 2 is taken, the sum is 2.
When only 3 is taken, the sum is 3.
When elements 2 and 3 are taken, the sum is 2 + 3 = 5.
*/


// approach s the basic conceept of backtrackng which we are doing for the sum part here 

#include<iostream>
#include<vectors>

void subsetSums(int i,int sum, vector<int>&arr,vector<int>&ans)
{
  if(i==arr.size()){
    ans.push_back(sum);
    return;
  }

  //take the element 
  subsetSums(i+1;sum+arr[i],arr[i],ans);
// donot take the element 
  subsetSums(i+1,sum,arr,ans);

  
}
