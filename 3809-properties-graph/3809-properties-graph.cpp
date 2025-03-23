class Solution {
vector<vector<int>>adj;
vector<bool>vist;

private:
// bool isValid(vector<int>&a,vector<int>&b,int k){
//     vector<bool>x(101,false);
//     for(auto &i:a){
//         x[i]=true;
//     }
//     int cnt=0;
//     for(auto &i:b){
//         if(x[i])
//             cnt++;
//     }
//     return cnt>=k;
// }

  int intersect(vector<int>& a,vector<int>& b) {
    bitset<101>bs1;
    bitset<101>bs2;
    for (int x:a)bs1.set(x);
    for (int x:b)bs2.set(x);
    return (bs1&bs2).count();
}
private:
void DFS(int node){
    if(vist[node])return;
    vist[node]=true;
    for(auto neigh:adj[node]){
        if(!vist[neigh]){
            DFS(neigh);
        }
    }
}
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        adj.resize(n);
        vist.assign(n+1,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ 
                int val=intersect(properties[i],properties[j]);
                if(val>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vist[i]){
                cnt++;
                DFS(i);
            }
        }

        return cnt;
    }
};