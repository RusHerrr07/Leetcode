class Solution {
public:
    void BFS(vector<vector<char>>& grid, int n, int m, int startX, int startY) {
        vector<int> dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
        for (int d = 0; d < 4; d++) {
            int x = startX, y = startY;
            while (true) {
                x += dx[d]; y += dy[d];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 'W' || grid[x][y] == 'G' ) break;
                grid[x][y] = '*';
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for (auto& wall : walls) grid[wall[0]][wall[1]] = 'W';
        for (auto& guard : guards) grid[guard[0]][guard[1]] = 'G';

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'G') {
                    BFS(grid, n, m, i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
