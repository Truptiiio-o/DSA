//shortest path in a undirected graph of edge weight =1 everywhere 
vector<int> shortestpath(vactor<vector<int>>&edges,int N , int M , int src){
  vector<int> adj[];
  for(auto it:edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  int dist[N];
  for(int i=0;i<N;i++){
    dis[i]=1e9;
  }
  dist[src]=0;
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    node=q.front();
    q.pop();
    for(auto it:adj[node]){
      if(dist[node]+1<dist[it]){
        dist[it]=dist[node]+1;
        q.push(it);
      }
    }
  }


  // afetr this do the rest work like however u are asked to return 
  //and also if not possible (that is some element is still left as 1e9 after whole traversal then return -1 and all do that according to the question
  
}
