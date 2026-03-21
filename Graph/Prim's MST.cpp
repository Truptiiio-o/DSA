#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V,vector<vector<int>> adj[]){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> vis(V,0);
  int mstWt=0;
  pq.push({0,0});// no need of parent if we want only sum of weights 
  // if we want to store the edges of the mst we can use a vector of pairs 
  // and push the edge into the vector when we pop it from the priority queue
  // and also check if the node is visited or not
  while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int node=it.second;
    int wt=it.first;
    if(vis[node]==1) continue;
    vis[node]=1;
    mstWt+=wt;
    for(auto it:adj[node]){
      int v=it.first;
      int w=it.second;
      if(!vis[v]){
        pq.push({w,v});
      }
    }
  }
  return mstWt;
}


// approach
/*
..... requirements are priority quque and vis array 
1. put the first src node into the priority queue (along with the weight and the parent if required according to the question )
2. pop it out and mark it as visited then push all its neighours into the priority quque ,,,,
3. as it is a min heap/priority quque the one with the smllest weught will be popped (it will be in the front) 
4. then with this repeat the steps 2 and 3 like MARK IT AS VISIITED AFTER POPPING IT 



*/
