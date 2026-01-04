int getnum(int i , int start , string &str){
  if(i<start) return;

  if(str[i]<'0' || str[i]>'9'){
    return 1e9;
  }
  int digit =str[i]-'0';
  int prev=getnum(i-1,start,str);
  if(prev==1e9) return 1e9;

  return prev*10 +digit;
}

int atoi(string str){
  int start=0;
  bool isnegative=false;
  int n=str.size();

  if(str[0]=='-'){
    start=1;
    isnegative =true;
  }

  int ans = getnum(n-1,start,str);
   if(ans==1e9) return -1;
   return isnegative? -ans:ans;
  
}
