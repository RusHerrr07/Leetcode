class Solution {
public:
    vector<int> g[100005], fg[100005];
    bool bad[100005];
    
    void dfs(int p){
        if (bad[p]) return;
        bad[p] = true;
        for (auto j : g[p]) dfs(j);
    }
    
    vector<int> remainingMethods(int n, int K, vector<vector<int>>& edges) {
        int i, j;
        for (i = 0; i < n; ++i) g[i].clear();
        for (i = 0; i < n; ++i) fg[i].clear();
        for (i = 0; i < n; ++i) bad[i] = false;
        for (auto e : edges){
            g[e[0]].push_back(e[1]);
            fg[e[1]].push_back(e[0]);
        }
        
        dfs(K);
        vector<int> res;
        for (auto e : edges)
            if (!bad[e[0]] && bad[e[1]]){
                for (i = 0; i < n; ++i) res.push_back(i);
                return res;
            }
            
        for (i = 0; i < n; ++i) 
            if (!bad[i]) res.push_back(i);
            
        return res;
    }
};