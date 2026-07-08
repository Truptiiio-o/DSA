#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
  vector<int> rank,parent;
public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
      parent[i]=i;
    }
  }

int findPar(int node){
  if(node==parent[node]) return node;
  return parent[node]=findPar(parent[node]);
}

void unionByRank(int u,int v){
  int pu=findPar(u);
  int pv=findPar(v);
  if(pu==pv) return;
  if(rank[pu]<rank[pv]){
    parent[pu]=pv;
  }else if(rank[pu]>rank[pv]){
    parent[pv]=pu;
  }else{
    parent[pu]=pv;
    rank[pv]++;
  }
}

};

int main() {
    // Note: Removed file I/O for standard terminal execution
    DisjointSet ds(7);
    
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    // Check if 3 and 7 are in the same component
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }
    ds.unionByRank(3, 7);
    // Check again
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }
    
    return 0;
}
