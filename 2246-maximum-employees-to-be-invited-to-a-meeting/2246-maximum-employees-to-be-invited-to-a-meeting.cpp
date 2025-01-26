class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        return max(maxCycle(favorite, n), maxChain(favorite, n));
    }

private:
   
    int maxCycle(vector<int>& favorite, int n) {
        vector<int> vis(n, 0), time(n, -1);
        int maxCycleSize = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsCycle(i, favorite, time, vis, maxCycleSize, 0);
            }
        }

        return maxCycleSize;
    }

    void dfsCycle(int u, vector<int>& favorite, vector<int>& time, vector<int>& vis, int& maxCycleSize, int t) {
        if (vis[u]) return;
        if (time[u] != -1) { 
            maxCycleSize = max(maxCycleSize, t - time[u]);
            return;
        }
        time[u] = t;
        dfsCycle(favorite[u], favorite, time, vis, maxCycleSize, t + 1);
        vis[u] = 1;
    }

    int maxChain(vector<int>& favorite, int n) {
        vector<int> indeg(n, 0), longest(n, 1);
        queue<int> q;

        for (int i = 0; i < n; i++) 
            indeg[favorite[i]]++;

        for (int i = 0; i < n; i++) 
            if (indeg[i] == 0) 
                q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            int v = favorite[u];
            longest[v] = max(longest[v], longest[u] + 1);
            if (--indeg[v] == 0) 
                q.push(v);
        }

        int sumChainPairs = 0;
        for (int i = 0; i < n; i++) {
            if (favorite[favorite[i]] == i && i < favorite[i]) 
                sumChainPairs += longest[i] + longest[favorite[i]];
        }

        return sumChainPairs;
    }
};