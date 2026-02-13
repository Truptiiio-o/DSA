/*QUESTION:
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.*/
void path(vector<string> &ans,string &curr,vector<vector<int>> &m, vector<vector<int>> &vis,int r,int c){
  int n=m.size();
  if(r==n-1 && c==n-1){
    ans.push_back(curr);
    return;
  }
   vis[r][c] = 1; 

if (r + 1 < n && m[r + 1][c] == 1 && vis[r + 1][c] == 0) {
        curr.push_back('D');
        path(ans, curr, m, vis, r + 1, c);
        curr.pop_back();
    }

    // Left
    if (c - 1 >= 0 && m[r][c - 1] == 1 && vis[r][c - 1] == 0) {
        curr.push_back('L');
        path(ans, curr, m, vis, r, c - 1);
        curr.pop_back();
    }

    // Right
    if (c + 1 < n && m[r][c + 1] == 1 && vis[r][c + 1] == 0) {
        curr.push_back('R');
        path(ans, curr, m, vis, r, c + 1);
        curr.pop_back();
    }

    // Up
    if (r - 1 >= 0 && m[r - 1][c] == 1 && vis[r - 1][c] == 0) {
        curr.push_back('U');
        path(ans, curr, m, vis, r - 1, c);
        curr.pop_back();
    }
  vis[r][c]=0;

}

vector<vector<string> maze(vector<vector<int>> &m){
 vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  string curr;
  if (m[0][0] == 1) path(ans,curr,m,vis,0,0);
  return ans;
}

  
}
