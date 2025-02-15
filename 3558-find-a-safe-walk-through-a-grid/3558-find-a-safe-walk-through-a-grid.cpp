class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int BFS(vector<vector<int>>& grid, int sx, int sy, int n, int m) {
        deque<pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[sx][sy] = 0;
        if(grid[0][0]==1){
            dist[0][0]=1;
        }
        dq.push_front({sx, sy});


        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int weight = grid[nx][ny];

                    if (dist[x][y] + weight < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + weight;

                        if (weight == 0) dq.push_front({nx, ny});
                        else dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int dist = BFS(grid, 0, 0, n, m);
        cout<<dist<<endl;
        health-=dist;
        return health>=1;
    }
};
