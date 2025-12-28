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
