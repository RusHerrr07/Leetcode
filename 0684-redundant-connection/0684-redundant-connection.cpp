class Solution {
    bool dfs(int v, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                if (dfs(u, v, adj, visited)) return true;
            } else if (u != parent) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];

            vector<bool> visited(n + 1, false);
            adj[u].push_back(v);
            adj[v].push_back(u);

            if (dfs(u, -1, adj, visited)) {
                return edge;
            }
        }

        return {-1, -1};
    }
};
