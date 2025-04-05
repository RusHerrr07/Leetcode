class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<int> dp;

    void dfs1(int u, int p) {
        for (auto &[v, cost] : adj[u]) {
            if (v != p) {
                dp[0] += cost;
                dfs1(v, u);
            }
        }
    }

    void dfs2(int u, int p) {
        for (auto &[v, cost] : adj[u]) {
            if (v != p) {
                dp[v] = dp[u] + (cost == 0 ? 1 : -1);
                dfs2(v, u);
            }
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        dp.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0}); 
            adj[v].push_back({u, 1});
        }

        dfs1(0, -1); 
        dfs2(0, -1);

        return dp;
    }
};
