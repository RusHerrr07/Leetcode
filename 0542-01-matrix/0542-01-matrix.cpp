class Solution {

int dx[4]={0,+1,0,-1};
int dy[4]={-1,0,+1,0};
public:
 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
             int i=q.front().first;
             int j=q.front().second;
             q.pop();
             for(int dir=0;dir<4;dir++){
                int x=i+dx[dir];
                int y=j+dy[dir];
                if(x>=0 && x<n && y>=0 && y<m && ans[x][y]==-1){
                    ans[x][y]=ans[i][j]+1;
                    q.push({x,y});
                }
             }
        }

        return ans;
    }
};
