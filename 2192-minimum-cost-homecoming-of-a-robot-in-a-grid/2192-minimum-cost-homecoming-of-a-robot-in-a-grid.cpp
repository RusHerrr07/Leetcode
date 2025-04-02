class Solution {
    //     if (dp[i][j] != -1) return; 
        
    //     dp[i][j] = 0;
        
    //     if (i + 1 < n) {
    //         dp[i + 1][j] = min(dp[i + 1][j] == -1 ? INT_MAX : dp[i + 1][j], dp[i][j] + rowCosts[i + 1]);
    //         DFS(i + 1, j, n, m, destX, destY, rowCosts, colCosts);
    //     }
        
    //     if (i - 1 >= 0) {
    //         dp[i - 1][j] = min(dp[i - 1][j] == -1 ? INT_MAX : dp[i - 1][j], dp[i][j] + rowCosts[i - 1]);
    //         DFS(i - 1, j, n, m, destX, destY, rowCosts, colCosts);
    //     }
        
    //     if (j + 1 < m) {
    //         dp[i][j + 1] = min(dp[i][j + 1] == -1 ? INT_MAX : dp[i][j + 1], dp[i][j] + colCosts[j + 1]);
    //         DFS(i, j + 1, n, m, destX, destY, rowCosts, colCosts);
    //     }
        
    //     if (j - 1 >= 0) {
    //         dp[i][j - 1] = min(dp[i][j - 1] == -1 ? INT_MAX : dp[i][j - 1], dp[i][j] + colCosts[j - 1]);
    //         DFS(i, j - 1, n, m, destX, destY, rowCosts, colCosts);
    //     }
    // }

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:

   int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // int n = rowCosts.size();
        // int m = colCosts.size();
        // int i = startPos[0]; 
        // int j = startPos[1]; 
        // int destX = homePos[0]; 
        // int destY = homePos[1];

        // vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        // pq.push({0, {i, j}});

        // int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // while (!pq.empty()) {
        //     auto val = pq.top();
        //     pq.pop();
        //     int row = val.second.first;
        //     int col = val.second.second;
        //     int cost = val.first;

        //     if (row == destX && col == destY) return cost;

         int sx = startPos[0], sy = startPos[1];
        int dx = homePos[0], dy = homePos[1];
        int cost = 0;
        if (sx < dx) {
            for (int i = sx + 1; i <= dx; i++) cost += rowCosts[i];
        } else {
            for (int i = sx - 1; i >= dx; i--) cost += rowCosts[i];
        }
        if (sy < dy) {
            for (int j = sy + 1; j <= dy; j++) cost += colCosts[j];
        } else {
            for (int j = sy - 1; j >= dy; j--) cost += colCosts[j];
        }

        return cost;
   }
};