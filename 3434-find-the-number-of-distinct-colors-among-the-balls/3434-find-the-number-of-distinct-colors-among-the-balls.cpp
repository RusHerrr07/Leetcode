class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),0);
        int cnt=0,idx=0;
        map<int, int> ball,clr;
        for (auto &i:queries) {
            int u = i[0];
            int v = i[1];
            if(ball.find(u)!=ball.end()){
                int x=ball[u];
                clr[x]--;
                if(clr[x]==0)cnt--;
                clr[v]++;
                if(clr[v]==1)cnt++;
            }
            else{
                if(clr[v]==0)cnt++;
                clr[v]++;
            }
            ball[u]=v;
            ans[idx++]=cnt;
        }

        return ans;
    }
};
