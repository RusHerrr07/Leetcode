class Solution {
public:
    int m, n, w = 0;
    vector<vector<bool>>v;
    vector<vector<int>>h;
    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; 

    // void dfs(int r, int c, int mh) {
    //     if (r < 0 || r >= m || c < 0 || c >= n || v[r][c]) return;
    //     v[r][c] = 1;
    //     if (h[r][c] < mh)w+=mh-h[r][c];
    //     int nh = max(mh, h[r][c]);
    //     for (int i = 0; i<4; i++) dfs(r+d[i][0],c +d[i][1], nh);
    // }


       void bfs(priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>&pq){
        while(!pq.empty()){
            auto[ch,p]=pq.top();pq.pop();
            int r=p.first,c=p.second;
            for(int i=0;i<4;i++){
                int nr=r+d[i][0],nc=c+d[i][1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&!v[nr][nc]){
                    v[nr][nc]=1;
                    w+=max(0,ch-h[nr][nc]);
                    pq.push({max(ch,h[nr][nc]),{nr,nc}});
                }
            }
        }
    }

    int trapRainWater(vector<vector<int>>& H) {
        // if (H.empty()) return 0;
        // h = H, m = h.size(), n = h[0].size(), v.assign(m, vector<bool>(n, 0));
        // for (int i = 0; i < m; i++) dfs(i, 0, h[i][0]), dfs(i, n - 1, h[i][n - 1]);
        // for (int j = 0; j < n; j++) dfs(0, j, h[0][j]), dfs(m - 1, j, h[m - 1][j]);
        // return w;

        if(H.empty())return 0;
        h=H,m=h.size(),n=h[0].size(),v.assign(m,vector<bool>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        for(int i=0;i<m;i++)
            pq.push({h[i][0],{i,0}}),pq.push({h[i][n-1],{i,n-1}}),v[i][0]=v[i][n-1]=1;
        for(int j=1;j<n-1;j++)
            pq.push({h[0][j],{0,j}}),pq.push({h[m-1][j],{m-1,j}}),v[0][j]=v[m-1][j]=1;
        bfs(pq);
        return w;
    }
};
