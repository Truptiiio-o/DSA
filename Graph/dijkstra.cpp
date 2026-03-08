//using priority queue
vector<int> dijkstra(int V,vector<vector<int>> adj[],int S){
  priority_queue<pair<int,int> , vector<pair<int,int>>, greatest<pair<int,int>>> pq;
  vector<int> dist(V);
  for(int i=0;i<V;i++){
    dist[i]=1e9;
  }
  dist[S]=0;
  pq.push({0,S});
  while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto it:adj[node]){
      int edgeweight=it[1];
      int adjnode=it[0];

      if(dis+edgeweight<dist[adjnode]){
        dist[adjnode]=dis+edgeweight;
        pq.push({dist[adjnode],adjnode});
      }
      
    }
  }
  return dist;
  
}


//APPROACH
/*
make a priority queuue and a dist arr 
push the src node into the pq
then pop the top of the pq and check for its adj 
if for any adj the dist+weight of that node < dist[that node] then update the dost arr and push the new dist,node in the pq
*/
