
class Solution {
private:
    int dp[201][201];

    int solve(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX, right = INT_MAX;
        if (i + 1 < n) down = grid[i][j] + solve(i + 1, j, n, m, grid);
        if (j + 1 < m) right = grid[i][j] + solve(i, j + 1, n, m, grid);
        dp[i][j] = min(down, right);
        return dp[i][j];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, m, grid);
    }
};
