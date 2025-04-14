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
        // DFS(0, n - 1);

        // vector<vector<int>> ans;
        // for (auto &i : st) {
        //     ans.push_back(i);
        // }
        // return ans;



        //let's solve using BFS;
         vector<vector<int>> ans;
         queue<vector<int>>q;
         vector<int>path;
         path.push_back(0);

         q.push(path);
         while(!q.empty()){
            auto arr=q.front();
            q.pop();
            if(arr.back()==n-1){
                ans.push_back(arr);
            }
            else{
                int node=arr.back();
                for(auto &neigh:adj[node]){
                    vector<int>naya=arr;
                    naya.push_back(neigh);
                    q.push(naya);
                }
            }
         }

         return ans;

    }
};
