class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        pair<int, int> source = make_pair(0, 0);
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        deque<pair<int,int>>q;
        q.push_front(source);
        vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
         while(!q.empty()){
            auto [x,y]=q.front();
            q.pop_front();
            for( int i=0;i<4;i++){
             int dx=x+dir[i][0];
             int dy=y+dir[i][1];
             if(dx>=0 && dy>=0 && dx<n && dy<m){
                int newdist=grid[dx][dy]+dist[x][y];
                if (dist[dx][dy] > newdist){
                    dist[dx][dy]=newdist;
                    if(grid[dx][dy]==0){
                    q.push_front({dx,dy});
                }
                else{
                    q.push_back({dx,dy});
                }
                }

                
             }
            }
         }

         return dist[n-1][m-1];
        
        
        
    }
};