void insert(stack<int> &str,int ele){

  if(str.empty() || str.top<=ele){
    str.push(ele);
    return;
  }

  int temp=str.top();
  str.pop();
  insert(str,ele);
  str.push(temp);
}

void sortStack(stack<int> &str){
  if(str.empty()) return;

  int top=str.top();
  str.pop();
  insert(str,top);
}
