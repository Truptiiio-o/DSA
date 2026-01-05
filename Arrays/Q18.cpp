#include<iostream>
using namespace std;

void approved(int count , int up , int x, vector<string> &ans, string s,int n){
  if(count==n && s.length()==2*n){ ans.push_back(s);
                                  return;}

  if(up>n) return;
  if(x<0) return;

  approved(count,up+1,x+1,ans,s+'(',n);
  approved(count+1,up,x-1,ans,s+')',n);
}

 vector<string> generateParenthesis(int n) {
   int count=0;
   int up=0;
   string s="";
   int x;
   vector<string> ans;
   
   approved(count,up,x,ans,s,n);

   return ans;
 }
