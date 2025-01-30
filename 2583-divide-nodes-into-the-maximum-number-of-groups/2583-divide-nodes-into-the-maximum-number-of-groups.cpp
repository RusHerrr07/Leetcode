
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
    int bfs(vector<vector<int>>& adj, int start, int n) {
        vector<int> level(n + 1, -1);
        queue<int> q;
        q.push(start);
        level[start] = 0;
        int layers = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            layers = max(layers, level[node]);

            for (int neigh : adj[node]) {
                if (level[neigh] == -1) {
                    level[neigh] = level[node] + 1;
                    q.push(neigh);
                } else if (level[neigh] == level[node]) {
                    return -1;
                }
            }
        }
        return layers + 1;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        DSU dsu(n);
        for (auto& edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }

        vector<vector<int>> components(n + 1);
        for (int i = 1; i <= n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        int maxi = 0;
        for (auto& comp : components) {
            if (comp.empty()) continue;

            int layers = -1;
            for (int start : comp) {
                int result = bfs(adj, start, n);
                if (result == -1) return -1;
                layers = max(layers, result);
            }
            maxi += layers;
        }

        return maxi;
    }
};