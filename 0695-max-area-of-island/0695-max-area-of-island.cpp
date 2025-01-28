class Solution {
private:
int maxi =0;
int dx[4] ={0,0,-1,1};
int dy[4] ={-1,1,0,0};
 int DFS(vector<vector<int>>& grid, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) 
        return 0;

    int ans = grid[i][j];
    grid[i][j] = 0; 

    for (int dir = 0; dir < 4; dir++) {
        int nrow = i + dx[dir], ncol = j + dy[dir];
        ans += DFS(grid, nrow, ncol, n, m);
    }

    return ans;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int n = grid.size(), m = grid[0].size();
        for (int i =0; i<n; i++)
            for (int j=0; j < m; j++)
                if (grid[i][j] != 0) 
                    // maxi = max(maxi, BFS(grid, i, j, n, m));
                    maxi = max(maxi, DFS(grid, i, j, n, m));
        return maxi;
        
    }
};