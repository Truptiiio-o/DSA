/*QUESTION 12:
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

*/

//we created our own power function that too for a very large number this method is commonly used in competitive programming 
// pow function can't work with large inputs 

#include<iostream>
#include<math>

using namespace std;
const long long MOD 1000000007;

long long power(long long base , long ong exp){
  long long result=1;
  while(exp>0){
    if(exp & 1){ result=(base*result)%MOD;
               }
    base=(base*base)%MOD;
    exp>>=1; /// this implies divide by 2 
  }
  return result;
  
}
long long goodNumber(int n){
  long long odd=n/2;
  long long  even=(n+1)/2;

  long long  ans =(power(5,even)*power(4,odd))%MOD;
  return ans;
  
}



//METHOD 2**************************
//aproach
//basically recurse call for calculating the answer directly no need of poer function 
//if it is odd say 3 then the places are   0 1 2 th position therefore %2 and check what to do
// if %2 ==0 then it was even nunber say 4 ... the positions will be 0 1 2 3 so mulitply prev(n-1)*4 % MOD as the last positoion number will be odd 
// similarly for the odd number case prev(n-1)*4 % MOD and continue like that 
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long solve(long long n) {
    // Base cases
    if (n == 0) return 1;   // empty string
    if (n == 1) return 5;   // even index → 5 choices

    long long prev = solve(n - 1);

    if (n % 2 == 0) {
        // last index is odd
        return (prev * 4) % MOD;
    } else {
        // last index is even
        return (prev * 5) % MOD;
    }
}

int countGoodNumbers(long long n) {
    return solve(n);
}
