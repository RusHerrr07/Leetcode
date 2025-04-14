class Solution {
    set<vector<int>> st;
    vector<vector<int>> adj;
    vector<int> path;

    void DFS(int node, int target) {
        path.push_back(node);
        if (node == target) {
            st.insert(path);
        } else {
            for (auto &neigh : adj[node]) {
                DFS(neigh, target);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        adj = graph;  
        DFS(0, n - 1);

        vector<vector<int>> ans;
        for (auto &i : st) {
            ans.push_back(i);
        }
        return ans;
    }
};
