/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
  */

class Solution {
public:


    void bfs (vector<vector<char>>& grid , vector<vector<int>> &vis ,int r,int c ){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        
        q.push({r,c});
        vis[r][c]=1;

        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};        

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nc>=0 && nr>=0 && nr<m && nc<n && grid[nr][nc]=='1' &&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,vis,i,j);
                    
                }
            }
        }

    return count;


    }
};
