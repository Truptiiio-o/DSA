/*QUESTION:
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]*/

bool isPalindrome(int start,int end,string s){
  while(start<=end){
    if(s[start]==s[end]){
      start++;
      end--;
      continue;
    }
    else return false;
  }
  return true;
}

void solve(string s,int start,vector<vector<string>> &v,vector<string> &current){
  if(start==s.length()){
    v.push_back(current);
    return;
  }

  for(int i=start;i<s.length();i++){
    if(isPalindrome(start,i,s)){
      current.push_back(s.substr(start,end-start+1));
      solve(s,i+1,v,current);
      current.pop_back();
    }
  }
}

vector<vector<string>> partition(string s){
  vector<vector<string>> v;
  vector<string> current;
  solve(s,0,v,current);
  return v;
  
}


//AAPROACH 
//Tc=O(2^n*n) where N is the length of the input string 's'. In the worst case, we can have 2^N possible partitions, and for each partition, we need to check if each substring is a palindrome, which takes O(N) time.
//Space Complexity: O(N), where N is the length of the input string 's'. The space is used for storing the temporary partition vector and the vector of partitions.
/*
basically what we did is recurrsion + backtracking thingy 
we created a palindrome function for checking if a substring is palindrome or nt 
and then he main part is the solve function where we decide the start and then iterate through the string by first taking one element then checking is till there it is sa 
pallindrome if it is then pass solve function for the remaining string 
then also followed by a popback to backtrack 
simlarly as the i value increases it take 2 at a time , 3 at a time and so on and this way u can check for each partition if the staring is palindrome till that partion and if 
the string is palindrome after that partition also
*/
