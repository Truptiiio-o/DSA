#include<iostream>
// detect a cycle in a graph using DFS
dfs(int node,int parent,vector<int> adj[],vector<int> vis[]){

  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[i]){
      if(dfs(it,node,adj,vis)==true) return true;
      else if(it!=parent) return true;
    }
  }
  return false;
}

int main(){
  
}

//SC = O(N)+O(N)
//TC=O(N+2E) 
