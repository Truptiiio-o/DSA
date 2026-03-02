#include<iostream>

bool dfs(int node,int col,int color[],vector<int> adj[]){
  color[node]=col;
  for(auto it:adj[node]){
    if(color[it]==-1){
      if(dfs(it,!col,color,adj)==false) return false;
    }
    else if(color[it]==col) return false;
  }
  return true;
}

// APPROACH 
/*
performing dfs such that using the colors as 0,1 to check if the graph can be bipartite or not 
initialise color array as -1 and fill the colors
if the color of the adj node wass already changed and it is equal to col then return false (for example we colored the node with 0 and the IT one of the adjacent was already visited as color[it]!=-1
with color[it]==col (that was filled in the node) soooo not bipartite
*/
int main(){}

//TC=O(N+2E)
//sc=O(N) for color array
