class Solution {
    const int mod = 1e9 + 7;
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(m));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto& entry : dp[i][j]) {
                    int currXor = entry.first;
                    int paths = entry.second;
                    if (i + 1 < n) {
                        dp[i + 1][j][currXor ^ grid[i + 1][j]] = (dp[i + 1][j][currXor ^ grid[i + 1][j]] + paths) % mod;
                    }
                    if (j + 1 < m) {
                        dp[i][j + 1][currXor ^ grid[i][j + 1]] = (dp[i][j + 1][currXor ^ grid[i][j + 1]] + paths) % mod;
                    }
                }
            }
        }
        return dp[n - 1][m - 1][k];
    }
};