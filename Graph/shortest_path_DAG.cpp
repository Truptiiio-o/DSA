#include<iostream>
using namespace std;

void toposort(int node,int vector<pair<int,int>> adj[],int vis[],stack<int> &st){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      int v=it.first;
      toposort(v,adj,vis,st);
    }
  }
  st.push(node);
  
}

vector<int> shortestpath(int N , int M , vector<int> edges[]){
  vector<pair<int,int>> adj[N];
  for(int i=0;i<N;i++){
    int u=edges[i][0];
    int v=edges[i][1];
    int wt=edges[i][2];
    adj[u].push_back({v,wt});


    //find the topo sort 
    int vis[N]={0};
    stack<int> st;
    for(int i=0;i<N;i++){
      if(!vis[i]){
        toposort(i,adj,vis,st);
      }
    }

    vector<int> dis(N);
    for(int i=0;i<N;i++) dist[i]=1e9;

    dist[0]=0;
    while(!st.empty()){
      int node=st.top();
      st.pop();
      for(auto it:adj[node]){
        if(dist[node]+it.second< it.first){
          it.first=dist[node]+it.second;
        }
      }
    }
    return dist;
  }
}

//toppo sort them to know the paths they can follow and on the baisis of that decie which one will be the shortest one to do so 

