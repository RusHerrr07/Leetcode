class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node]) continue;
            for (auto &val : adj[node]) {
                int neigh = val.first;
                int weight = val.second;
                if (dist[neigh] > dist[node] + weight) {
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == 1e9 ? -1 : res;
    }
};