#include<iostream>

veoid dfs(int node, int vis[],stack st,vector<int> adj[]){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      dfs(it,vis,st,adj);
    }
  }
  st.push(node);
}

//approach 
/*
basically whenevr we have travelled the dfs a partuclarnode completely then push them into the stack startin from the end 

*/
