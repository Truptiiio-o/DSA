#include<iostream>

/// detect a cycle in a graph using BFS 
bool detect(int src,vector<int> adj[],int vis[]){
  vis[src]=1;
  queue<pair<int,int>> q;
  q.push({src,-1});
  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto it:adj[node]){
      if(!vis[it]){
        vis[it]=1;
        q.push({it,node});
      }
      else if(parent!=it){
        return true;
      }
    }
  }
  return false;
}


int main(){

 // smthg smtg
}


//TC=O(N+2E)
  //sc=O(N)
