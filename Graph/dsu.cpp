/// You are given an undirected graph with n  nodes numbered from 1 to n Initially, the graph contains no edges, so each node forms its own connected component.
//For the next k days, exactly one edge is added to the graph. On day i, an edge is added between from[i] and to[i].
//The strength of a connected component is defined as the largest numbered node present in that component. A connected component consisting of a single node x has strength x
//After adding the edge on each day, compute the total strength of the graph, which is the sum of the strengths of all connected components currently present.
//Return an array where the ith element denotes the total strength of the graph after the edge added on day i.

class DSU{
  vector<int> parent;
  vector<int> strength;
  long long totalstrength;

  DSU(int n){
    parent.resize(n+1);
    strength.resize(n+1);
    totalstrength=0;

    for(int i=1,i<=n;i++){
      parent[i]=i;
      strength[i]=i;
      totalstrength+=i;
    }
  }

int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

void union(int i,int j){
  int pu=find(i);
  int pv=find(j);

  if(pu!=pv){
    totalstrength-=strength[pu];
    totalstrength-=strength[pv];
    parent[pu]=pv;
    strength[pv]=max(strength[pv],strength[pu]);
    totalstrength+=strength[pv];
  }
}

};


vector<long long> componentStrengths(int n, std::vector<int>& from, std::vector<int>& to) {
    int k = from.size();
    vector<long long> ans(k);
    DSU dsu(n);
    
    for (int i = 0; i < k; ++i) {
        dsu.union(from[i], to[i]);
        ans[i] = dsu.totalstrength;
    }
    
    return ans;
}

