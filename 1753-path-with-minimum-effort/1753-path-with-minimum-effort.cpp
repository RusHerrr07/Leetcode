class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto val = pq.top();
            pq.pop();
            int d = val.first;
            int i = val.second.first;
            int j = val.second.second;
            
            if (d > dist[i][j]) continue;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int nDist = max(d, abs(heights[i][j] - heights[ni][nj]));
                    if (nDist < dist[ni][nj]) {
                        dist[ni][nj] = nDist;
                        pq.push({nDist, {ni, nj}});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};