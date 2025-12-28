/*Given an array Arr of size N, print the second largest distinct element from an array.
Example:
Input:
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the
array is 35 and the second largest element
is 34.
*/

#include<iostream>
using namespace std;

int scnd_largest(int n, int a[]){
  int largest=a[0];
  int scndLargest=-1;
  for(int i=1;i<n;i++){
    if(a[i]>largest){
      scndLargest=largest;
      largest=a[i];      
    }
    if(a[i]<largest && a[i]>scndLargest){
      scndLargest=a[i];
    }
  }
return scndLargest;
  
}
