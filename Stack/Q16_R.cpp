void insertatBottom(stack<int> &str,int ele){
  if(str.empty()){
    str.push(ele);
    return;
  }

  int temp=str.top();
  str.pop();
  insertatBottom(str,ele);
  str.push(temp); 

}

void reverseStack(stack<int> &str){
  if(str.empty()) return;

  int top=str.top();
  str.pop();
  reverseStack(str);
  insertatBottom(str,top);
  
}
