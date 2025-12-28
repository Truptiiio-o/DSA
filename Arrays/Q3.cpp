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
