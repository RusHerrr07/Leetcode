// class Solution {
// public:
//     using pii = pair<int, int>;
//     const int INF = 1e9;
//     vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

//     void dfs(vector<vector<int>>& grid, vector<vector<int>>& cost, int i, int j, int c) {
//         int m = grid.size(), n = grid[0].size();
//         if (i < 0 || j < 0 || i >= m || j >= n || c >= cost[i][j]) return;
//         cost[i][j] = c;
//         for (int k = 0; k < 4; k++) {
//             int ni = i + dx[k], nj = j + dy[k];
//             dfs(grid, cost, ni, nj, c + (grid[i][j] != k + 1));
//         }
//     }

//     int minCost(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> cost(m, vector<int>(n, INF));
//         dfs(grid, cost, 0, 0, 0);
//         return cost[m - 1][n - 1];
//     }
// };




class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0}; 
        
        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int new_cost = cost[i][j] + (grid[i][j] != k + 1);
                    if (new_cost < cost[ni][nj]) {
                        cost[ni][nj] = new_cost;
                        if (grid[i][j] == k + 1) dq.push_front({ni, nj});
                        else dq.push_back({ni, nj});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
