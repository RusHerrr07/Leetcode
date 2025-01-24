class Solution {
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int zeroOneBFS(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        deque<pair<int,int>> q;
        q.push_back({0,0});
        dist[0][0] = 1;
        while (!q.empty()) {
            int i=q.front().first,j=q.front().second;
            q.pop_front();
            for (int x=0;x<8;x++) {
                int ni =i+dx[x],nj=j+dy[x];
                if (ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0) {
                    if (dist[i][j]+1<dist[ni][nj]) {
                        dist[ni][nj]=dist[i][j]+1;
                        q.push_back({ni,nj});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if (grid[0][0]==1||grid[n-1][m-1]==1) return -1;
        int ans= zeroOneBFS(grid,n,m);
        return ans==1e9?-1:ans;
    }
};
