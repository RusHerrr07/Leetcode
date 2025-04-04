class Solution {
map<int,set<int>>mp;
int ans=0;
vector<vector<pair<int,int>>>adj;
vector<bool>vist;
private:
void DFS(int src){
    if(vist[src])return;
    vist[src]=true;
    // set<int>st=mp[src];
    for(auto &neigh:adj[src]){
        int cnt=neigh.second;
        int node=neigh.first;
        if(!vist[node]){
            ans+=cnt;
            DFS(node);
        }
    }
}
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      adj.resize(n);
      vist.assign(n,false);
      for(auto &i:connections){
        int u=i[0];
        int v=i[1];
        // mp[u].insert(v);
        adj[u].push_back({v,1});
        adj[v].push_back({u,0});
      }
      DFS(0);
      return ans;
    }
};
