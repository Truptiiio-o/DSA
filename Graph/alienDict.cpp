#include<iostream>
string findOrder(int N,int K,string Dict[]){
  vector<int> adj[K];
  for(int i=0;i<N-1;i++){
    string s1=dict[i];
    string s2=dict[i+1];
    int len=min(s1.size(),s2.sze());
    for(int j=0;i<len;j++){
      if(s1[j]!=s2[j]){
        adj[s1[j]-'a'].push_back(s2[j]-'a');
        break;
      }
    }
  }

  vetor<int> topo=topoSort(K,adj[]);///apply the topo sort fucntion 
  string ans="";
  for(auto it:topo){
    ans+= char(it+'a');
  }
  return ans;
}

// approach 
/* basically we need to make the dictionary whih these aleins use 
so we are checking what is coming before what 
and making an adj list according to it 
once we have the adj list basiclaly we have the graph
now after applying topo sort on this graph we will get the proper order required 
*/
