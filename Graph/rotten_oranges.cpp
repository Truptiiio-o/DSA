/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
    */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minutes = 0;

        while (!q.empty()) {
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            int size = q.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        rottedThisMinute = true;
                    }
                }
            }
            if (rottedThisMinute) minutes++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};

        //BASICALLY WE USED BFS CUZ WE NEED TO CHECK THE ENIGHBOURS OR THAT LEEL EENTS FRIST RATHER THAN GOING TO THE DEPTH 
        // BOTH WOULD WORK BUT BFS IS BETTER 
        /*
APPROACH
1) since the rotten oranges number will be anyways canged to 2 , so no need f a sperate viisted array 
2) normal bfs travel but here the chnage is the maintaining a time variable 
3)we need to increment the time when all the neighbours of a rotten orange are rotten , if no orange got rotten then no increment in time 
4) so we created a time variable that gets increment only once while its neighbours are getting rotten

            */

