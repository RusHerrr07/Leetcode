class Solution {
public:
    int minJumps(vector<int>& arr) {

        map<int,vector<int>>mp;
        int n = arr.size();

        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool>vist(arr.size(),false);

        queue<pair<int,int>>q;
        q.push({0,0});
        vist[0] = true;

        while(!q.empty()){
            auto x=q.front();
            int idx=x.first;
            int dist=x.second;
            q.pop();
            if(idx==n-1){
                return dist;
            }
            for(auto &neigh:mp[arr[idx]]){
                if(!vist[neigh]){
                    vist[neigh]=true;
                    q.push({neigh,dist+1});
                }
            }
            mp[arr[idx]].clear();
            if(idx+1<n && !vist[idx+1]){
                q.push({idx+1,dist+1});
                vist[idx+1]=true;
            }

     
            if(idx-1>=0 && !vist[idx-1]){
                q.push({idx-1,dist+1});
                vist[idx-1]=true;
            }

        }
        return -1;
    }
};
