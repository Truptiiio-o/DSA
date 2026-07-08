#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> size, parent;
public:
    // Constructor
    DisjointSet(int n) {
        // 1-based indexing safety (n+1)
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find Ultimate Parent with Path Compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        // Path Compression
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
      int pu=findUPar(u);
      int pv=findUPar(v);
      if(pu==pv) return;
      if(size[pu]<size[pv]){
        parent[pu]=pv;
        size[pv]+=size[pu];
      }else{
        parent[pv]=pu;
        size[pu]+=size[pv];
      }
    }
};

int main() {
    DisjointSet ds(7);
    
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    // Check if 3 and 7 are in the same component
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }
    ds.unionBySize(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }
    
    return 0;
}
