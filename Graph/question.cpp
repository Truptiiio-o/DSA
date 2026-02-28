#include<iostream>

/// detect a cycle in a graph using BFS 
bool detect(int src,vector<int> adj[],int vis[]){
  vis[src]=1;
  queue<pair<int,int>> q;
  q.push({src,-1});
  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;
    
  }
}


