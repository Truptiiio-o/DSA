/*
Question:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example:
Input: s = "the sky is blue"
Output: "blue is sky the"
*/
/*
APPROACH 
1. basically what i was thinking is going from end traversing one word and reversing it and then again starting an so on , i was going character by character 
2. while the easier approach would be to traverse until one word gets completed push it into a vector 
2. like this push all the words into a vector 
then use reverse function on the vector 
then simply concatenate the string 

TC=O(n)
SC=O(n)
  */

string reverse(string s){

  vector<string> words;
  int i=0;
  int n=s.length();

  while(i<n){

    while(i<n && s[i]==' ') i++;

    if(i>=n) break;
    int j=i;
    while(j<n && s[i]!=' ') j++;

    words.push_back(s.substr(i,j-i));
    i=j;}

    reverse(words.begin(),words.end());

    string ans="";
    for(int k=0;k<words.size();k++){
      if(k>0) ans+=' ';
      ans+=words[k];
    }
  return ans;
}
