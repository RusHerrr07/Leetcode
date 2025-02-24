class Solution {
map<int,int>bob;
int maxi=INT_MIN;

bool DFS1(unordered_map<int,vector<int>>&adj,int curr,vector<bool>&vist,int time){
    if(curr==0){
        return true;
    }
    bob[curr]=time;

    for(auto &padosi:adj[curr]){
        if(!vist[padosi]){
            vist[padosi]=true;
            if(DFS1(adj,padosi,vist,time+1)){
                return true;
            }
            vist[padosi]=false; // Backtrack krlooo
        }
    }
    bob.erase(curr); 
    return false;
}

void DFS(unordered_map<int,vector<int>>&adj,int curr,int time,int money,vector<bool>&vist,vector<int>&amount){

    if(bob.find(curr)==bob.end() || bob[curr]>time ){
        money+=amount[curr];  
    }
    else if(bob[curr]==time){
        money+=amount[curr] / 2;
    }
    if(adj[curr].size() == 1 && curr != 0){ 
        maxi = max(money, maxi);
        return;
    }

    vist[curr] = true;
    for(auto &padosi:adj[curr]){
        if(!vist[padosi]){
            DFS(adj,padosi,time+1,money,vist,amount);
        }
    }
    vist[curr] = false; 
}

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    unordered_map<int,vector<int>>adj;
    for(auto &i:edges){
        auto u=i[0];
        auto v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int n=amount.size();

    vector<bool>vist(n,false);
    vist[bob]=true;
    DFS1(adj,bob,vist,0);
    
    fill(vist.begin(),vist.end(),false);
    DFS(adj,0,0,0,vist,amount);
    
    return maxi; 
    }
};