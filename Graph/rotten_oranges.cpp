

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

