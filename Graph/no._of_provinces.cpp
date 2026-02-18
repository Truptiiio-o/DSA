/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
return the number of provinces 

*/


#include<iostream>

void dfs(vector<vector<int>> &isConnected,int node,vector<int> &vis){
  ves[node]=1;
  for(int j=0;i<isConnected.size();j++){
    if(isConnected[node][j]==1 && !vis[node]){
      dfs(isConnected,j,vis);
    }
  }
}

int findCircleNum(vector<vector<int>>& isConnected) {
  int n=isConnected.size();
  vector<int> vis(n,0);
  int provinces =0;
  for(int i=0;i<n;i++){
    if(!vis[i]){
    provinces++;
      dfs(isConnected,i,vis);
    }
  }
  return provinces;
  
}


//Tc=O(n^2) this is because we check for each node that its visited or not and we call the dfs function which again scans through that nodes all the neighbours so worst case will be O(n^2)
// the vector used for visited and also the stack used during the recurssion for dfs O(n)
/*APPROACH 
1. THE PROVINCES ARE THE BASICALLY THE CONNECTED AREAS/GRAPHS ... SO WHENVER WE FIND THAT A VIS==0 THEN THAT WAS NOT VISITED BECUASE THE PREVIOUS TRAVERSAL ENDED AND IT WAS NOT CONNECTED TO THE PREVIOUS ONE 
2.NOW FOR THE DFS PART 
3. IT CHNAGES THE VIISTED VALUE FROM 0 TO 1
4. THEN HERE WE DON'T HAVE ADJACENCY LIST SO FOR ADJACENCY MATRIX WE SEARCH FOR THAT PARTICULAR NODE WHICH J ==1 AND IS NOT VISITED ...IF FOUND THEN DO DFS OVER THERE 

*/
